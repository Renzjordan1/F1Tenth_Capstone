from setuptools import find_packages
from setuptools import setup

setup(
    name='my_messages',
    version='0.0.0',
    packages=find_packages(
        include=('my_messages', 'my_messages.*')),
)
