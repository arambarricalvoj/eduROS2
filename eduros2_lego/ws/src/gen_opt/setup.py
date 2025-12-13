from setuptools import find_packages, setup

package_name = 'gen_opt'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', [package_name + '/launch/zuzen_objektuarenganaino.py']),
        ('share/' + package_name + '/config', [package_name + '/config/params.yaml']),
    ],
    install_requires=['setuptools', 'transformations'],
    zip_safe=True,
    maintainer='Javier Arambarri Calvo',
    maintainer_email='javierarambarricalvo@gmail.com',
    description='gen_opt',
    #license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'pid_gen_opt = gen_opt.zuzen_objektuarenganaino:main',
        ],
    },
)
