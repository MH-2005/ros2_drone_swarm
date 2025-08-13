# generated from rosidl_generator_py/resource/_idl.py.em
# with input from swarm_msgs:srv/ChangeFormation.idl
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


class Metaclass_ChangeFormation_Request(type):
    """Metaclass of message 'ChangeFormation_Request'."""

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
                'swarm_msgs.srv.ChangeFormation_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__change_formation__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__change_formation__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__change_formation__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__change_formation__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__change_formation__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ChangeFormation_Request(metaclass=Metaclass_ChangeFormation_Request):
    """Message class 'ChangeFormation_Request'."""

    __slots__ = [
        '_formation_type',
        '_orientation',
        '_size',
        '_altitude',
        '_move_x',
        '_move_y',
        '_move_z',
        '_rotate_x',
        '_rotate_y',
        '_rotate_z',
        '_execute_simultaneously',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'formation_type': 'string',
        'orientation': 'string',
        'size': 'double',
        'altitude': 'double',
        'move_x': 'double',
        'move_y': 'double',
        'move_z': 'double',
        'rotate_x': 'double',
        'rotate_y': 'double',
        'rotate_z': 'double',
        'execute_simultaneously': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
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
        self.formation_type = kwargs.get('formation_type', str())
        self.orientation = kwargs.get('orientation', str())
        self.size = kwargs.get('size', float())
        self.altitude = kwargs.get('altitude', float())
        self.move_x = kwargs.get('move_x', float())
        self.move_y = kwargs.get('move_y', float())
        self.move_z = kwargs.get('move_z', float())
        self.rotate_x = kwargs.get('rotate_x', float())
        self.rotate_y = kwargs.get('rotate_y', float())
        self.rotate_z = kwargs.get('rotate_z', float())
        self.execute_simultaneously = kwargs.get('execute_simultaneously', bool())

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
        if self.move_x != other.move_x:
            return False
        if self.move_y != other.move_y:
            return False
        if self.move_z != other.move_z:
            return False
        if self.rotate_x != other.rotate_x:
            return False
        if self.rotate_y != other.rotate_y:
            return False
        if self.rotate_z != other.rotate_z:
            return False
        if self.execute_simultaneously != other.execute_simultaneously:
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
    def move_x(self):
        """Message field 'move_x'."""
        return self._move_x

    @move_x.setter
    def move_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'move_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'move_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._move_x = value

    @builtins.property
    def move_y(self):
        """Message field 'move_y'."""
        return self._move_y

    @move_y.setter
    def move_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'move_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'move_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._move_y = value

    @builtins.property
    def move_z(self):
        """Message field 'move_z'."""
        return self._move_z

    @move_z.setter
    def move_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'move_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'move_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._move_z = value

    @builtins.property
    def rotate_x(self):
        """Message field 'rotate_x'."""
        return self._rotate_x

    @rotate_x.setter
    def rotate_x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'rotate_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rotate_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rotate_x = value

    @builtins.property
    def rotate_y(self):
        """Message field 'rotate_y'."""
        return self._rotate_y

    @rotate_y.setter
    def rotate_y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'rotate_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rotate_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rotate_y = value

    @builtins.property
    def rotate_z(self):
        """Message field 'rotate_z'."""
        return self._rotate_z

    @rotate_z.setter
    def rotate_z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'rotate_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'rotate_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._rotate_z = value

    @builtins.property
    def execute_simultaneously(self):
        """Message field 'execute_simultaneously'."""
        return self._execute_simultaneously

    @execute_simultaneously.setter
    def execute_simultaneously(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'execute_simultaneously' field must be of type 'bool'"
        self._execute_simultaneously = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_ChangeFormation_Response(type):
    """Metaclass of message 'ChangeFormation_Response'."""

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
                'swarm_msgs.srv.ChangeFormation_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__change_formation__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__change_formation__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__change_formation__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__change_formation__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__change_formation__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ChangeFormation_Response(metaclass=Metaclass_ChangeFormation_Response):
    """Message class 'ChangeFormation_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_execution_time',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'execution_time': 'double',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
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
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        self.execution_time = kwargs.get('execution_time', float())

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
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        if self.execution_time != other.execution_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if self._check_fields:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def execution_time(self):
        """Message field 'execution_time'."""
        return self._execution_time

    @execution_time.setter
    def execution_time(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'execution_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'execution_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._execution_time = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_ChangeFormation_Event(type):
    """Metaclass of message 'ChangeFormation_Event'."""

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
                'swarm_msgs.srv.ChangeFormation_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__change_formation__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__change_formation__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__change_formation__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__change_formation__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__change_formation__event

            from service_msgs.msg import ServiceEventInfo
            if ServiceEventInfo.__class__._TYPE_SUPPORT is None:
                ServiceEventInfo.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ChangeFormation_Event(metaclass=Metaclass_ChangeFormation_Event):
    """Message class 'ChangeFormation_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<swarm_msgs/ChangeFormation_Request, 1>',
        'response': 'sequence<swarm_msgs/ChangeFormation_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['swarm_msgs', 'srv'], 'ChangeFormation_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['swarm_msgs', 'srv'], 'ChangeFormation_Response'), 1),  # noqa: E501
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
        from service_msgs.msg import ServiceEventInfo
        self.info = kwargs.get('info', ServiceEventInfo())
        self.request = kwargs.get('request', [])
        self.response = kwargs.get('response', [])

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
        if self.info != other.info:
            return False
        if self.request != other.request:
            return False
        if self.response != other.response:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def info(self):
        """Message field 'info'."""
        return self._info

    @info.setter
    def info(self, value):
        if self._check_fields:
            from service_msgs.msg import ServiceEventInfo
            assert \
                isinstance(value, ServiceEventInfo), \
                "The 'info' field must be a sub message of type 'ServiceEventInfo'"
        self._info = value

    @builtins.property
    def request(self):
        """Message field 'request'."""
        return self._request

    @request.setter
    def request(self, value):
        if self._check_fields:
            from swarm_msgs.srv import ChangeFormation_Request
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
                 len(value) <= 1 and
                 all(isinstance(v, ChangeFormation_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'ChangeFormation_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from swarm_msgs.srv import ChangeFormation_Response
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
                 len(value) <= 1 and
                 all(isinstance(v, ChangeFormation_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'ChangeFormation_Response'"
        self._response = value


class Metaclass_ChangeFormation(type):
    """Metaclass of service 'ChangeFormation'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('swarm_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'swarm_msgs.srv.ChangeFormation')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__change_formation

            from swarm_msgs.srv import _change_formation
            if _change_formation.Metaclass_ChangeFormation_Request._TYPE_SUPPORT is None:
                _change_formation.Metaclass_ChangeFormation_Request.__import_type_support__()
            if _change_formation.Metaclass_ChangeFormation_Response._TYPE_SUPPORT is None:
                _change_formation.Metaclass_ChangeFormation_Response.__import_type_support__()
            if _change_formation.Metaclass_ChangeFormation_Event._TYPE_SUPPORT is None:
                _change_formation.Metaclass_ChangeFormation_Event.__import_type_support__()


class ChangeFormation(metaclass=Metaclass_ChangeFormation):
    from swarm_msgs.srv._change_formation import ChangeFormation_Request as Request
    from swarm_msgs.srv._change_formation import ChangeFormation_Response as Response
    from swarm_msgs.srv._change_formation import ChangeFormation_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
