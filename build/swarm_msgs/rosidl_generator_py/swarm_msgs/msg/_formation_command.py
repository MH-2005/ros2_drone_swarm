# generated from rosidl_generator_py/resource/_idl.py.em
# with input from swarm_msgs:msg/FormationCommand.idl
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


class Metaclass_FormationCommand(type):
    """Metaclass of message 'FormationCommand'."""

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
            module = import_type_support('swarm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'swarm_msgs.msg.FormationCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__formation_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__formation_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__formation_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__formation_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__formation_command

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from geometry_msgs.msg import Vector3
            if Vector3.__class__._TYPE_SUPPORT is None:
                Vector3.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FormationCommand(metaclass=Metaclass_FormationCommand):
    """Message class 'FormationCommand'."""

    __slots__ = [
        '_formation_type',
        '_orientation',
        '_size',
        '_altitude',
        '_spacing',
        '_center_point',
        '_rotation_angle',
        '_translation',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'formation_type': 'string',
        'orientation': 'string',
        'size': 'double',
        'altitude': 'double',
        'spacing': 'double',
        'center_point': 'geometry_msgs/Point',
        'rotation_angle': 'double',
        'translation': 'geometry_msgs/Vector3',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Vector3'),  # noqa: E501
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
        self.formation_type = kwargs.get('formation_type', str())
        self.orientation = kwargs.get('orientation', str())
        self.size = kwargs.get('size', float())
        self.altitude = kwargs.get('altitude', float())
        self.spacing = kwargs.get('spacing', float())
        from geometry_msgs.msg import Point
        self.center_point = kwargs.get('center_point', Point())
        self.rotation_angle = kwargs.get('rotation_angle', float())
        from geometry_msgs.msg import Vector3
        self.translation = kwargs.get('translation', Vector3())

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
        if self.formation_type != other.formation_type:
            return False
        if self.orientation != other.orientation:
            return False
        if self.size != other.size:
            return False
        if self.altitude != other.altitude:
            return False
        if self.spacing != other.spacing:
            return False
        if self.center_point != other.center_point:
            return False
        if self.rotation_angle != other.rotation_angle:
            return False
        if self.translation != other.translation:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def formation_type(self):
        """Message field 'formation_type'."""
        return self._formation_type

    @formation_type.setter
    def formation_type(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'formation_type' field must be of type 'str'"
        self._formation_type = value

    @builtins.property
    def orientation(self):
        """Message field 'orientation'."""
        return self._orientation

    @orientation.setter
    def orientation(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'orientation' field must be of type 'str'"
        self._orientation = value

    @builtins.property
    def size(self):
        """Message field 'size'."""
        return self._size

    @size.setter
    def size(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'size' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'size' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._size = value

    @builtins.property
    def altitude(self):
        """Message field 'altitude'."""
        return self._altitude

    @altitude.setter
    def altitude(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'altitude' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'altitude' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._altitude = value

    @builtins.property
    def spacing(self):
        """Message field 'spacing'."""
        return self._spacing

    @spacing.setter
    def spacing(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'spacing' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'spacing' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._spacing = value

    @builtins.property
    def center_point(self):
        """Message field 'center_point'."""
        return self._center_point

    @center_point.setter
    def center_point(self, value):
        if self._check_fields:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'center_point' field must be a sub message of type 'Point'"
        self._center_point = value

    @builtins.property
    def rotation_angle(self):
        """Message field 'rotation_angle'."""
        return self._rotation_angle

    @rotation_angle.setter
    def rotation_angle(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'rotation_angle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rotation_angle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rotation_angle = value

    @builtins.property
    def translation(self):
        """Message field 'translation'."""
        return self._translation

    @translation.setter
    def translation(self, value):
        if self._check_fields:
            from geometry_msgs.msg import Vector3
            assert \
                isinstance(value, Vector3), \
                "The 'translation' field must be a sub message of type 'Vector3'"
        self._translation = value
