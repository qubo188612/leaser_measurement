# generated from rosidl_generator_py/resource/_idl.py.em
# with input from tutorial_interfaces:srv/IfAlgorhmit.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_IfAlgorhmit_Request(type):
    """Metaclass of message 'IfAlgorhmit_Request'."""

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
            module = import_type_support('tutorial_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tutorial_interfaces.srv.IfAlgorhmit_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__if_algorhmit__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__if_algorhmit__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__if_algorhmit__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__if_algorhmit__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__if_algorhmit__request

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IfAlgorhmit_Request(metaclass=Metaclass_IfAlgorhmit_Request):
    """Message class 'IfAlgorhmit_Request'."""

    __slots__ = [
        '_imagein',
    ]

    _fields_and_field_types = {
        'imagein': 'sensor_msgs/Image',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import Image
        self.imagein = kwargs.get('imagein', Image())

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
        if self.imagein != other.imagein:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def imagein(self):
        """Message field 'imagein'."""
        return self._imagein

    @imagein.setter
    def imagein(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'imagein' field must be a sub message of type 'Image'"
        self._imagein = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_IfAlgorhmit_Response(type):
    """Metaclass of message 'IfAlgorhmit_Response'."""

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
            module = import_type_support('tutorial_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tutorial_interfaces.srv.IfAlgorhmit_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__if_algorhmit__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__if_algorhmit__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__if_algorhmit__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__if_algorhmit__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__if_algorhmit__response

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

            from tutorial_interfaces.msg import IfAlgorhmitpoint2f
            if IfAlgorhmitpoint2f.__class__._TYPE_SUPPORT is None:
                IfAlgorhmitpoint2f.__class__.__import_type_support__()

            from tutorial_interfaces.msg import IfAlgorhmittargetpoint2f
            if IfAlgorhmittargetpoint2f.__class__._TYPE_SUPPORT is None:
                IfAlgorhmittargetpoint2f.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IfAlgorhmit_Response(metaclass=Metaclass_IfAlgorhmit_Response):
    """Message class 'IfAlgorhmit_Response'."""

    __slots__ = [
        '_result',
        '_imageout',
        '_targetpointout',
        '_lasertrackout',
    ]

    _fields_and_field_types = {
        'result': 'boolean',
        'imageout': 'sensor_msgs/Image',
        'targetpointout': 'sequence<tutorial_interfaces/IfAlgorhmittargetpoint2f>',
        'lasertrackout': 'sequence<tutorial_interfaces/IfAlgorhmitpoint2f>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tutorial_interfaces', 'msg'], 'IfAlgorhmittargetpoint2f')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['tutorial_interfaces', 'msg'], 'IfAlgorhmitpoint2f')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.result = kwargs.get('result', bool())
        from sensor_msgs.msg import Image
        self.imageout = kwargs.get('imageout', Image())
        self.targetpointout = kwargs.get('targetpointout', [])
        self.lasertrackout = kwargs.get('lasertrackout', [])

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
        if self.result != other.result:
            return False
        if self.imageout != other.imageout:
            return False
        if self.targetpointout != other.targetpointout:
            return False
        if self.lasertrackout != other.lasertrackout:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'result' field must be of type 'bool'"
        self._result = value

    @property
    def imageout(self):
        """Message field 'imageout'."""
        return self._imageout

    @imageout.setter
    def imageout(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            assert \
                isinstance(value, Image), \
                "The 'imageout' field must be a sub message of type 'Image'"
        self._imageout = value

    @property
    def targetpointout(self):
        """Message field 'targetpointout'."""
        return self._targetpointout

    @targetpointout.setter
    def targetpointout(self, value):
        if __debug__:
            from tutorial_interfaces.msg import IfAlgorhmittargetpoint2f
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
                 all(isinstance(v, IfAlgorhmittargetpoint2f) for v in value) and
                 True), \
                "The 'targetpointout' field must be a set or sequence and each value of type 'IfAlgorhmittargetpoint2f'"
        self._targetpointout = value

    @property
    def lasertrackout(self):
        """Message field 'lasertrackout'."""
        return self._lasertrackout

    @lasertrackout.setter
    def lasertrackout(self, value):
        if __debug__:
            from tutorial_interfaces.msg import IfAlgorhmitpoint2f
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
                 all(isinstance(v, IfAlgorhmitpoint2f) for v in value) and
                 True), \
                "The 'lasertrackout' field must be a set or sequence and each value of type 'IfAlgorhmitpoint2f'"
        self._lasertrackout = value


class Metaclass_IfAlgorhmit(type):
    """Metaclass of service 'IfAlgorhmit'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('tutorial_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'tutorial_interfaces.srv.IfAlgorhmit')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__if_algorhmit

            from tutorial_interfaces.srv import _if_algorhmit
            if _if_algorhmit.Metaclass_IfAlgorhmit_Request._TYPE_SUPPORT is None:
                _if_algorhmit.Metaclass_IfAlgorhmit_Request.__import_type_support__()
            if _if_algorhmit.Metaclass_IfAlgorhmit_Response._TYPE_SUPPORT is None:
                _if_algorhmit.Metaclass_IfAlgorhmit_Response.__import_type_support__()


class IfAlgorhmit(metaclass=Metaclass_IfAlgorhmit):
    from tutorial_interfaces.srv._if_algorhmit import IfAlgorhmit_Request as Request
    from tutorial_interfaces.srv._if_algorhmit import IfAlgorhmit_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
