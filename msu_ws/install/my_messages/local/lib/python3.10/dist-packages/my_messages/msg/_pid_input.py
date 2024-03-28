# generated from rosidl_generator_py/resource/_idl.py.em
# with input from my_messages:msg/PIDInput.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PIDInput(type):
    """Metaclass of message 'PIDInput'."""

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
            module = import_type_support('my_messages')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'my_messages.msg.PIDInput')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__pid_input
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__pid_input
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__pid_input
            cls._TYPE_SUPPORT = module.type_support_msg__msg__pid_input
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__pid_input

            from my_messages.msg import KeyValue
            if KeyValue.__class__._TYPE_SUPPORT is None:
                KeyValue.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PIDInput(metaclass=Metaclass_PIDInput):
    """Message class 'PIDInput'."""

    __slots__ = [
        '_pid_vel',
        '_pid_error',
    ]

    _fields_and_field_types = {
        'pid_vel': 'float',
        'pid_error': 'sequence<my_messages/KeyValue>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['my_messages', 'msg'], 'KeyValue')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pid_vel = kwargs.get('pid_vel', float())
        self.pid_error = kwargs.get('pid_error', [])

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
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
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.pid_vel != other.pid_vel:
            return False
        if self.pid_error != other.pid_error:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pid_vel(self):
        """Message field 'pid_vel'."""
        return self._pid_vel

    @pid_vel.setter
    def pid_vel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pid_vel' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'pid_vel' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._pid_vel = value

    @builtins.property
    def pid_error(self):
        """Message field 'pid_error'."""
        return self._pid_error

    @pid_error.setter
    def pid_error(self, value):
        if __debug__:
            from my_messages.msg import KeyValue
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, KeyValue) for v in value) and
                 True), \
                "The 'pid_error' field must be a set or sequence and each value of type 'KeyValue'"
        self._pid_error = value
