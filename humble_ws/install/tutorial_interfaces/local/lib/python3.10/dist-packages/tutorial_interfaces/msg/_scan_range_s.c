// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from tutorial_interfaces:msg/ScanRange.idl
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
#include "tutorial_interfaces/msg/detail/scan_range__struct.h"
#include "tutorial_interfaces/msg/detail/scan_range__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool tutorial_interfaces__msg__scan_range__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("tutorial_interfaces.msg._scan_range.ScanRange", full_classname_dest, 45) == 0);
  }
  tutorial_interfaces__msg__ScanRange * ros_message = _ros_message;
  {  // min
    PyObject * field = PyObject_GetAttrString(_pymsg, "min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->min = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // max
    PyObject * field = PyObject_GetAttrString(_pymsg, "max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->max = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * tutorial_interfaces__msg__scan_range__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ScanRange */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("tutorial_interfaces.msg._scan_range");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ScanRange");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  tutorial_interfaces__msg__ScanRange * ros_message = (tutorial_interfaces__msg__ScanRange *)raw_ros_message;
  {  // min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
