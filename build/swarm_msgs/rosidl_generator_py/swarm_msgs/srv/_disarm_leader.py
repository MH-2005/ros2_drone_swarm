# generated from rosidl_generator_py/resource/_idl.py.em
# with input from swarm_msgs:srv/DisarmLeader.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DisarmLeader_Request(type):
    """Metaclass of message 'DisarmLeader_Request'."""

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
                'swarm_msgs.srv.DisarmLeader_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__disarm_leader__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__disarm_leader__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__disarm_leader__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__disarm_leader__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__disarm_leader__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DisarmLeader_Request(metaclass=Metaclass_DisarmLeader_Request):
    """Message class 'DisarmLeader_Request'."""

    __slots__ = [
        '_leader_id',
        '_return_to_home',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'leader_id': 'int32',
        'return_to_home': 'boolean',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
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
        self.leader_id = kwargs.get('leader_id', int())
        self.return_to_home = kwargs.get('return_to_home', bool())

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
        if self.leader_id != other.leader_id:
            return False
        if self.return_to_home != other.return_to_home:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def leader_id(self):
        """Message field 'leader_id'."""
        return self._leader_id

    @leader_id.setter
    def leader_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'leader_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'leader_id' field must be an integer in [-2147483648, 2147483647]"
        self._leader_id = value

    @builtins.property
    def return_to_home(self):
        """Message field 'return_to_home'."""
        return self._return_to_home

    @return_to_home.setter
    def return_to_home(self, value):
        if self._check_fields:
            assert \
                isinstance(value, bool), \
                "The 'return_to_home' field must be of type 'bool'"
        self._return_to_home = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_DisarmLeader_Response(type):
    """Metaclass of message 'DisarmLeader_Response'."""

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
                'swarm_msgs.srv.DisarmLeader_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__disarm_leader__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__disarm_leader__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__disarm_leader__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__disarm_leader__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__disarm_leader__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DisarmLeader_Response(metaclass=Metaclass_DisarmLeader_Response):
    """Message class 'DisarmLeader_Response'."""

    __slots__ = [
        '_success',
        '_old_leader_id',
        '_new_leader_id',
        '_message',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'old_leader_id': 'int32',
        'new_leader_id': 'int32',
        'message': 'string',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
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
        self.old_leader_id = kwargs.get('old_leader_id', int())
        self.new_leader_id = kwargs.get('new_leader_id', int())
        self.message = kwargs.get('message', str())

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
        if self.old_leader_id != other.old_leader_id:
            return False
        if self.new_leader_id != other.new_leader_id:
            return False
        if self.message != other.message:
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
    def old_leader_id(self):
        """Message field 'old_leader_id'."""
        return self._old_leader_id

    @old_leader_id.setter
    def old_leader_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'old_leader_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'old_leader_id' field must be an integer in [-2147483648, 2147483647]"
        self._old_leader_id = value

    @builtins.property
    def new_leader_id(self):
        """Message field 'new_leader_id'."""
        return self._new_leader_id

    @new_leader_id.setter
    def new_leader_id(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'new_leader_id' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'new_leader_id' field must be an integer in [-2147483648, 2147483647]"
        self._new_leader_id = value

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


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_DisarmLeader_Event(type):
    """Metaclass of message 'DisarmLeader_Event'."""

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
                'swarm_msgs.srv.DisarmLeader_Event')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__disarm_leader__event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__disarm_leader__event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__disarm_leader__event
            cls._TYPE_SUPPORT = module.type_support_msg__srv__disarm_leader__event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__disarm_leader__event

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


class DisarmLeader_Event(metaclass=Metaclass_DisarmLeader_Event):
    """Message class 'DisarmLeader_Event'."""

    __slots__ = [
        '_info',
        '_request',
        '_response',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'info': 'service_msgs/ServiceEventInfo',
        'request': 'sequence<swarm_msgs/DisarmLeader_Request, 1>',
        'response': 'sequence<swarm_msgs/DisarmLeader_Response, 1>',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['service_msgs', 'msg'], 'ServiceEventInfo'),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['swarm_msgs', 'srv'], 'DisarmLeader_Request'), 1),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.NamespacedType(['swarm_msgs', 'srv'], 'DisarmLeader_Response'), 1),  # noqa: E501
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
            from swarm_msgs.srv import DisarmLeader_Request
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
                 all(isinstance(v, DisarmLeader_Request) for v in value) and
                 True), \
                "The 'request' field must be a set or sequence with length <= 1 and each value of type 'DisarmLeader_Request'"
        self._request = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if self._check_fields:
            from swarm_msgs.srv import DisarmLeader_Response
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
                 all(isinstance(v, DisarmLeader_Response) for v in value) and
                 True), \
                "The 'response' field must be a set or sequence with length <= 1 and each value of type 'DisarmLeader_Response'"
        self._response = value


class Metaclass_DisarmLeader(type):
    """Metaclass of service 'DisarmLeader'."""

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
                'swarm_msgs.srv.DisarmLeader')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__disarm_leader

            from swarm_msgs.srv import _disarm_leader
            if _disarm_leader.Metaclass_DisarmLeader_Request._TYPE_SUPPORT is None:
                _disarm_leader.Metaclass_DisarmLeader_Request.__import_type_support__()
            if _disarm_leader.Metaclass_DisarmLeader_Response._TYPE_SUPPORT is None:
                _disarm_leader.Metaclass_DisarmLeader_Response.__import_type_support__()
            if _disarm_leader.Metaclass_DisarmLeader_Event._TYPE_SUPPORT is None:
                _disarm_leader.Metaclass_DisarmLeader_Event.__import_type_support__()


class DisarmLeader(metaclass=Metaclass_DisarmLeader):
    from swarm_msgs.srv._disarm_leader import DisarmLeader_Request as Request
    from swarm_msgs.srv._disarm_leader import DisarmLeader_Response as Response
    from swarm_msgs.srv._disarm_leader import DisarmLeader_Event as Event

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
