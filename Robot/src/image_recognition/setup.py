from setuptools import setup, find_packages
import os
from glob import glob

package_name = 'image_recognition'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(),
    data_files=[
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
        (os.path.join('share', package_name, 'resource'), glob('resource/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='tu_nombre',
    maintainer_email='tu_email@example.com',
    description='Paquete de ROS 2 para reconocimiento de imágenes usando Keras.',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'image_recognition = image_recognition.image_recognition:main',
            'image_recognition_subscriber = image_recognition.image_recognition_subscriber:main'
        ],
    },
)
