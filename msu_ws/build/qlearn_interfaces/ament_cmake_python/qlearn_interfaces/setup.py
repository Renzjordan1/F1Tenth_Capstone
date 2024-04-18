from setuptools import find_packages
from setuptools import setup

setup(
    name='qlearn_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('qlearn_interfaces', 'qlearn_interfaces.*')),
)
