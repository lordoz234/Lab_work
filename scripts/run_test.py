import subprocess
import glob
import os
import random
import sys
from typing import Tuple


def test(array: list, executable_path: str) -> Tuple[bool, list, list]:
    """
    Function to test

    Parameters
    ----------
    array : Array
        list
    executable_path : Path to execution file
        str

    Returns
    -------
    True/False and actual, expected arrays
    """
    args = str(len(array)) + "\n"
    args += "\n".join(str(x) for x in array)

    res = subprocess.run(
        [executable_path], input=args.encode(), check=True, capture_output=True
    )

    result = [int(x) for x in res.stdout.decode().split(" ")[:-1]]

    return result == sorted(array), result, sorted(array)


def get_random_array(num: int) -> list:
    """
    Function to get random array

    Parameters
    ----------
    num : Number of elements in array
        int

    Returns
    -------
    Random Array
    """
    random_array = [random.randint(1, 10000) for _ in range(num)]

    return random_array


if __name__ == "__main__":
    directory_path = "build/task3"

    all_files = os.listdir(directory_path)

    executable_files = [
        file
        for file in all_files
        if os.stat(os.path.join(directory_path, file)).st_mode & 0o100 != 0
        and file != "CMakeFiles"
    ]

    for executable_file in executable_files:
        ex = "./" + directory_path + "/" + executable_file
        for _ in range(5):
            length = random.randint(1, 100)
            res, actual, expected = test(get_random_array(length), ex)
            if not res:
                print("Wrong Answer")
                print("Actual: ", actual)
                print("Expected: ", expected)
                sys.exit(1)

    print("All Done!!!")
