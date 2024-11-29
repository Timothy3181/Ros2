from setuptools import find_packages
from setuptools import setup

setup(
    name='practice',
    version='0.0.0',
    packages=find_packages(
        include=('practice', 'practice.*')),
)
