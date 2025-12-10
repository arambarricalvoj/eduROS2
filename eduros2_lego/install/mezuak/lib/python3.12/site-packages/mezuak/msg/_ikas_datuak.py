# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mezuak:msg/IkasDatuak.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_IkasDatuak(type):
    """Metaclass of message 'IkasDatuak'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mezuak')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mezuak.msg.IkasDatuak')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ikas_datuak
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ikas_datuak
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ikas_datuak
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ikas_datuak
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ikas_datuak

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IkasDatuak(metaclass=Metaclass_IkasDatuak):
    """Message class 'IkasDatuak'."""

    __slots__ = [
        '_pos_izq',
        '_pos_der',
        '_vel_izq',
        '_vel_der',
        '_yaw',
        '_error_traj',
        '_delta_v',
        '_dist_restante',
        '_reward',
        '_done',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'pos_izq': 'double',
        'pos_der': 'double',
        'vel_izq': 'double',
        'vel_der': 'double',
        'yaw': 'double',
        'error_traj': 'double',
        'delta_v': 'double',
        'dist_restante': 'double',
        'reward': 'float',
        'done': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pos_izq = kwargs.get('pos_izq', float())
        self.pos_der = kwargs.get('pos_der', float())
        self.vel_izq = kwargs.get('vel_izq', float())
        self.vel_der = kwargs.get('vel_der', float())
        self.yaw = kwargs.get('yaw', float())
        self.error_traj = kwargs.get('error_traj', float())
        self.delta_v = kwargs.get('delta_v', float())
        self.dist_restante = kwargs.get('dist_restante', float())
        self.reward = kwargs.get('reward', float())
        self.done = kwargs.get('done', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pos_izq != other.pos_izq:
            return False
        if self.pos_der != other.pos_der:
            return False
        if self.vel_izq != other.vel_izq:
            return False
        if self.vel_der != other.vel_der:
            return False
        if self.yaw != other.yaw:
            return False
        if self.error_traj != other.error_traj:
            return False
        if self.delta_v != other.delta_v:
            return False
        if self.dist_restante != other.dist_restante:
            return False
        if self.reward != other.reward:
            return False
        if self.done != other.done:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pos_izq(self):
        """Message field 'pos_izq'."""
        return self._pos_izq

    @pos_izq.setter
    def pos_izq(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'pos_izq' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pos_izq' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pos_izq = value

    @builtins.property
    def pos_der(self):
        """Message field 'pos_der'."""
        return self._pos_der

    @pos_der.setter
    def pos_der(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'pos_der' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pos_der' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pos_der = value

    @builtins.property
    def vel_izq(self):
        """Message field 'vel_izq'."""
        return self._vel_izq

    @vel_izq.setter
    def vel_izq(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'vel_izq' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_izq' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_izq = value

    @builtins.property
    def vel_der(self):
        """Message field 'vel_der'."""
        return self._vel_der

    @vel_der.setter
    def vel_der(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'vel_der' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'vel_der' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._vel_der = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'yaw' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._yaw = value

    @builtins.property
    def error_traj(self):
        """Message field 'error_traj'."""
        return self._error_traj

    @error_traj.setter
    def error_traj(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'error_traj' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'error_traj' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._error_traj = value

    @builtins.property
    def delta_v(self):
        """Message field 'delta_v'."""
        return self._delta_v

    @delta_v.setter
    def delta_v(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'delta_v' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'delta_v' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._delta_v = value

    @builtins.property
    def dist_restante(self):
        """Message field 'dist_restante'."""
        return self._dist_restante

    @dist_restante.setter
    def dist_restante(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'dist_restante' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dist_restante' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dist_restante = value

    @builtins.property
    def reward(self):
        """Message field 'reward'."""
        return self._reward

    @reward.setter
    def reward(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'reward' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'reward' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._reward = value

    @builtins.property
    def done(self):
        """Message field 'done'."""
        return self._done

    @done.setter
    def done(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'done' field must be of type 'bool'"
        self._done = value
