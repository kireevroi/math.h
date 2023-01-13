import os
import subprocess
import sys

PATH_TO_PROJECT = '/'.join(os.path.abspath(os.path.dirname(sys.argv[0])).split('/')[:-1])
build_stderr = sys.stdout
build_stdout = sys.stdout

part = sys.argv[1]


def build_static_library(library_dir='src', stage='run'):
    try:
        subprocess.run(['make', 'test'], cwd=PATH_TO_PROJECT + '/' + library_dir)
        build_result = subprocess.run(['make', stage],
                                      stderr=build_stderr, stdout=build_stdout, text=True,
                                      cwd=PATH_TO_PROJECT + '/' + library_dir)
    except Exception as e:
        return -1

    return build_result.returncode


static_library_build_result = build_static_library()
if static_library_build_result == 0:
    print('\n\nProject test: OK\n1')
else:
    print('\n\nProject test: FAIL\n0')

