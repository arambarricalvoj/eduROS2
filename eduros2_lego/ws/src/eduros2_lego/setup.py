from setuptools import find_packages, setup

package_name = 'eduros2_lego'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', [package_name + '/launch/display.launch.py']),
        ('share/' + package_name + '/launch', [package_name + '/launch/zuzen_objektuarenganaino.py']),
        ('share/' + package_name + '/launch', [package_name + '/launch/zuzen_pid_objektuarenganaino.py']),
        ('share/' + package_name + '/launch', [package_name + '/launch/fuzzy_zuzen.py']),
        ('share/' + package_name + '/launch', [package_name + '/launch/fuzzy_nn_zuzen.py']),
        ('share/' + package_name + '/config', [package_name + '/config/params.yaml']),
        ('share/' + package_name + '/sim', [package_name + '/sim/robot.urdf']),
        ('share/' + package_name + '/sim', [package_name + '/sim/conf.rviz']),
    ],
    install_requires=['setuptools', 'transformations'],
    zip_safe=True,
    maintainer='Javier Arambarri Calvo',
    maintainer_email='javierarambarricalvo@gmail.com',
    description='eduros2_lego: robótica educativa Lego con ROS2',
    #license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'teklatua = eduros2_lego.teklatua:main',
            'mugimendu_motorrak = eduros2_lego.mugimendu_motorrak:main',
            'ultrasoinu_sentsorea = eduros2_lego.ultrasoinu_sentsorea:main',
            'biraketa_sentsorea = eduros2_lego.biraketa_sentsorea:main',
            'kolore_sentsorea = eduros2_lego.kolore_sentsorea:main',
            'joint_states = eduros2_lego.joint_states:main',
            'mando = eduros2_lego.mando:main',
            'zuzen_objektuarenganaino = eduros2_lego.zuzen_objektuarenganaino:main',
            'datuen_erregistratzailea = eduros2_lego.registro:main'
        ],
    },
)
