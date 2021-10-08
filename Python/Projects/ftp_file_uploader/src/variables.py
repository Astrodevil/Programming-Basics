from datetime import datetime, timedelta

# GET THE DATE YESTERDAY
DATE = datetime.now()

# TURN THE DATETIME TO STRING
DATE = datetime.strftime(DATE, '%Y-%m-%d')

PARENT_DIR = './outputs/'
OUTPUT_DIR = datetime.strftime(DATE, '%m-%d-%Y(%H_%M)')
FILES_TO_GATHER = [
    'sample1.csv',
    'sample2.xlsx',
    'sample3.txt',
]

# for windows/DOS users
# SPECIFIC_DIRECTORIES = {
#   'dir1': r"D:\AUTOMATION\GITHUB\samples\",
#   'dir2': r"D:\AUTOMATION\LEETCODE\samples\"
# }

# for unix/ unix-like users (mac and linux)
SPECIFIC_DIRECTORIES = {
    'dir1': r'/home/use/Code/work/AUTOMATION/GITHUB/samples/',
}
