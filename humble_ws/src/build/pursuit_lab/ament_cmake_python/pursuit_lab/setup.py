from setuptools import find_packages
from setuptools import setup

setup(
    name='pursuit_lab',
    version='0.0.0',
    packages=find_packages(
        include=('pursuit_lab', 'pursuit_lab.*')),
)
