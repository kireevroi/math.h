import os
import subprocess
import sys
import re

PATH_TO_PROJECT = '/'.join(os.path.abspath(os.path.dirname(sys.argv[0])).split('/')[:-1])
build_stderr = sys.stdout
build_stdout = sys.stdout

part = sys.argv[1]


def build_static_library(library_dir='src', stage='valgrind'):
    try:
        result = 0
        build_result = subprocess.Popen(['make', stage],
                                      stderr=subprocess.PIPE, stdout=subprocess.PIPE, text=True,
                                      cwd=PATH_TO_PROJECT + '/' + library_dir)
        err, out = build_result.communicate()
        print(err)
        print(out)
        not_leaks = re.search("All heap blocks were freed", out)
        not_errors = re.search("ERROR SUMMARY: 0 errors from 0 contexts", out)
        if not_leaks and not_errors:
            result = 0
        else:
            result = -1
    except Exception as e:
        return -1

    return result


static_library_build_result = build_static_library()
if static_library_build_result == 0:
    print('\n\nValgrind test: OK\n1')
else:
    print('\n\nValgrind test: FAIL\n0')

