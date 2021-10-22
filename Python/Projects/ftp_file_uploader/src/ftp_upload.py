from configparser import ConfigParser
from src.variables import *
import os
import time
import sys
import ftplib
import base64
import shutil
import pyfiglet
import ntpath
from colorama import Fore
from os.path import expanduser


def folder_upload(argument=''):
    # PRINT HEADER
    header = pyfiglet.figlet_format("FTP TOOL")
    print(header)

    there_is_files_to_be_uploaded = gather_files(argument)
    if there_is_files_to_be_uploaded == True:
        ftp_upload()
    else:
        print('THere is no file to be uploaded')


def ftp_upload():
    config = ConfigParser()
    config.read('./configs.ini')

    HOSTNAME = config['FTP']['hostname']
    DIRECTORY = '/' + config['FTP']['working_dir']
    USERNAME = decode_base64(config['FTP']['username'])
    PASSWORD = decode_base64(config['FTP']['password'])

    try:
        with ftplib.FTP_TLS(HOSTNAME, USERNAME, PASSWORD, encoding='ISO-8859-1') as ftp:
            ftp.cwd(DIRECTORY)
            if not OUTPUT_DIR in ftp.nlst():
                ftp.mkd(OUTPUT_DIR)
            ftp.cwd(OUTPUT_DIR)

            path = PARENT_DIR + OUTPUT_DIR

            files = os.listdir(path)
            print(Fore.MAGENTA, 'Uploading files to the FTP Server...')
            for filename in files:
                with open(filename, "rb") as file:
                    # use FTP's STOR command to upload the file
                    ftp.storbinary(f"STOR {filename}", file)
    except Exception as error:
        print(Fore.RED, error)
        print(Fore.GREEN, '---> Go to the README file for the possible solution.')
        return

    print(Fore.GREEN, 'files succesfully uploaded')
    print(Fore.GREEN, '--> VIEW ALL THE OUTPUTS IN THE OUTPUTS FOLDER <--')


def gather_files(argument):
    # CREATING THE OUTPUT FOLDER
    path = PARENT_DIR + OUTPUT_DIR
    try:
        os.mkdir(path)
    except FileExistsError:
        # directory already exists, clean the directory
        for filename in os.listdir(path):
            file_path = os.path.join(path, filename)
            try:
                if os.path.isfile(file_path) or os.path.islink(file_path):
                    os.unlink(file_path)
                elif os.path.isdir(file_path):
                    shutil.rmtree(file_path)
            except Exception as e:
                print('Failed to delete %s. Reason: %s' % (file_path, e))
            return find_files_in_specific_directory(path)


def find_files_in_specific_directory(path):
    gathered_files = []

    # GATHER THE NEEDED FILES IN EACH SPECIFIC DIRECTORIES
    for directory in SPECIFIC_DIRECTORIES.items():
        directory_path = directory[1]
        print(Fore.MAGENTA, f'SCANNING: {directory_path}')
        if os.path.isdir(directory_path):
            directory_files = os.listdir(directory_path)
            for file in directory_files:
                if file in FILES_TO_GATHER:
                    gathered_files.append(os.path.join(directory_path, file))
        else:
            print(Fore.RED, f'{directory_path} is not existing..')

    # COPY ALL THE GATHERED FILES IN THE OUTPUT FOLDER
    if len(gathered_files):
        print(Fore.MAGENTA, 'Copying files to the output directory...')
        print(Fore.RESET, '', end="")
        for file in gathered_files:
            # filename = file.split('\\')[-1]
            filename = ntpath.basename(file)
            output_file = os.path.join(path, filename)
            print(output_file)
            shutil.copyfile(file, output_file)
        return True
    else:
        print(Fore.RED, 'THERE ARE NO FILES TO BE UPLOADED!')
        return False


def decode_base64(value):
    val = " " + value + " =="
    base64_bytes = val.encode("utf-8")
    string_bytes = base64.b64decode(base64_bytes)
    return string_bytes.decode("utf-8")
