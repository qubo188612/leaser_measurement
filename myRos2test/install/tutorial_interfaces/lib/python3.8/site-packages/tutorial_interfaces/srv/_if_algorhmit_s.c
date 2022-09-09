// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tutorial_interfaces:srv/IfAlgorhmit.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "tutorial_interfaces/srv/detail/if_algorhmit__struct.h"
#include "tutorial_interfaces/srv/detail/if_algorhmit__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool tutorial_interfaces__srv__if_algorhmit__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[58];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("tutorial_interfaces.srv._if_algorhmit.IfAlgorhmit_Request", full_classname_dest, 57) == 0);
  }
  tutorial_interfaces__srv__IfAlgorhmit_Request * ros_message = _ros_message;
  {  // imagein
    PyObject * field = PyObject_GetAttrString(_pymsg, "imagein");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->imagein)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tutorial_interfaces__srv__if_algorhmit__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of IfAlgorhmit_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tutorial_interfaces.srv._if_algorhmit");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "IfAlgorhmit_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tutorial_interfaces__srv__IfAlgorhmit_Request * ros_message = (tutorial_interfaces__srv__IfAlgorhmit_Request *)raw_ros_message;
  {  // imagein
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->imagein);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "imagein", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "tutorial_interfaces/srv/detail/if_algorhmit__struct.h"
// already included above
// #include "tutorial_interfaces/srv/detail/if_algorhmit__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "tutorial_interfaces/msg/detail/if_algorhmitpoint2f__functions.h"
#include "tutorial_interfaces/msg/detail/if_algorhmittargetpoint2f__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool sensor_msgs__msg__image__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * sensor_msgs__msg__image__convert_to_py(void * raw_ros_message);
bool tutorial_interfaces__msg__if_algorhmittargetpoint2f__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tutorial_interfaces__msg__if_algorhmittargetpoint2f__convert_to_py(void * raw_ros_message);
bool tutorial_interfaces__msg__if_algorhmitpoint2f__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * tutorial_interfaces__msg__if_algorhmitpoint2f__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool tutorial_interfaces__srv__if_algorhmit__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[59];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("tutorial_interfaces.srv._if_algorhmit.IfAlgorhmit_Response", full_classname_dest, 58) == 0);
  }
  tutorial_interfaces__srv__IfAlgorhmit_Response * ros_message = _ros_message;
  {  // result
    PyObject * field = PyObject_GetAttrString(_pymsg, "result");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->result = (Py_True == field);
    Py_DECREF(field);
  }
  {  // imageout
    PyObject * field = PyObject_GetAttrString(_pymsg, "imageout");
    if (!field) {
      return false;
    }
    if (!sensor_msgs__msg__image__convert_from_py(field, &ros_message->imageout)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // targetpointout
    PyObject * field = PyObject_GetAttrString(_pymsg, "targetpointout");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'targetpointout'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence__init(&(ros_message->targetpointout), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create tutorial_interfaces__msg__IfAlgorhmittargetpoint2f__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    tutorial_interfaces__msg__IfAlgorhmittargetpoint2f * dest = ros_message->targetpointout.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!tutorial_interfaces__msg__if_algorhmittargetpoint2f__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // lasertrackout
    PyObject * field = PyObject_GetAttrString(_pymsg, "lasertrackout");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'lasertrackout'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence__init(&(ros_message->lasertrackout), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create tutorial_interfaces__msg__IfAlgorhmitpoint2f__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    tutorial_interfaces__msg__IfAlgorhmitpoint2f * dest = ros_message->lasertrackout.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!tutorial_interfaces__msg__if_algorhmitpoint2f__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tutorial_interfaces__srv__if_algorhmit__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of IfAlgorhmit_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tutorial_interfaces.srv._if_algorhmit");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "IfAlgorhmit_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tutorial_interfaces__srv__IfAlgorhmit_Response * ros_message = (tutorial_interfaces__srv__IfAlgorhmit_Response *)raw_ros_message;
  {  // result
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->result ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "result", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // imageout
    PyObject * field = NULL;
    field = sensor_msgs__msg__image__convert_to_py(&ros_message->imageout);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "imageout", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // targetpointout
    PyObject * field = NULL;
    size_t size = ros_message->targetpointout.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    tutorial_interfaces__msg__IfAlgorhmittargetpoint2f * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->targetpointout.data[i]);
      PyObject * pyitem = tutorial_interfaces__msg__if_algorhmittargetpoint2f__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "targetpointout", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lasertrackout
    PyObject * field = NULL;
    size_t size = ros_message->lasertrackout.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    tutorial_interfaces__msg__IfAlgorhmitpoint2f * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->lasertrackout.data[i]);
      PyObject * pyitem = tutorial_interfaces__msg__if_algorhmitpoint2f__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "lasertrackout", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
