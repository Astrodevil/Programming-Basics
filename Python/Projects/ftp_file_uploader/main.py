import sys
import subprocess
import pkg_resources

# Install all the project dependencies


def check_dependencies():
    required = {'pyfiglet', 'colorama'}
    installed = {pkg.key for pkg in pkg_resources.working_set}
    missing = required - installed

    if missing:
        python = sys.executable
        print('installing dependencies....')
        subprocess.check_call([python, '-m', 'pip', 'install', *missing])


if __name__ == '__main__':
    try:
        from src.ftp_upload import *
    except ModuleNotFoundError:
        check_dependencies()
    finally:
        from src.ftp_upload import *
        try:
            folder_upload()
        except Exception as error:
            print(Fore.RED, error)
            print(Fore.GREEN, '---> Go to the README file for the possible solution.')
