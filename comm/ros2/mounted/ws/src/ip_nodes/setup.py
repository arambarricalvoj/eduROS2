from setuptools import find_packages, setup

package_name = 'ip_nodes'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', [package_name + '/launch/display.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='root',
    maintainer_email='root@todo.todo',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'teklatua = ip_nodes.teklatua:main',
            #'motorrak = ip_nodes.motorrak:main',
            #'odom = ip_nodes.subscriber_odom_member_function:main',
            'mugimendu_motorrak = ip_nodes.mugimendu_motorrak:main',
            'ultrasoinu_sentsorea = ip_nodes.ultrasoinu_sentsorea:main',
        ],
    },
)
