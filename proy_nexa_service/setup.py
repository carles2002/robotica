from setuptools import setup
import os #incluir
from glob import glob #incluir

package_name = 'proy_nexa_service'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name), glob('launch/*.launch.py'))
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='chen',
    maintainer_email='rchen1@epsg.upv.es',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'proy_nexa_movement_server = proy_nexa_service.proy_nexa_movement_server:main',
            'proy_nexa_movement_client = proy_nexa_service.proy_nexa_movement_client:main'
        ],
    },
)
