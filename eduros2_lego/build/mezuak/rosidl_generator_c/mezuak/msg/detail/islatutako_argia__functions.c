// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mezuak:msg/IslatutakoArgia.idl
// generated code does not contain a copyright notice
#include "mezuak/msg/detail/islatutako_argia__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
mezuak__msg__IslatutakoArgia__init(mezuak__msg__IslatutakoArgia * msg)
{
  if (!msg) {
    return false;
  }
  // argi_intentsitateak
  return true;
}

void
mezuak__msg__IslatutakoArgia__fini(mezuak__msg__IslatutakoArgia * msg)
{
  if (!msg) {
    return;
  }
  // argi_intentsitateak
}

bool
mezuak__msg__IslatutakoArgia__are_equal(const mezuak__msg__IslatutakoArgia * lhs, const mezuak__msg__IslatutakoArgia * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // argi_intentsitateak
  for (size_t i = 0; i < 2; ++i) {
    if (lhs->argi_intentsitateak[i] != rhs->argi_intentsitateak[i]) {
      return false;
    }
  }
  return true;
}

bool
mezuak__msg__IslatutakoArgia__copy(
  const mezuak__msg__IslatutakoArgia * input,
  mezuak__msg__IslatutakoArgia * output)
{
  if (!input || !output) {
    return false;
  }
  // argi_intentsitateak
  for (size_t i = 0; i < 2; ++i) {
    output->argi_intentsitateak[i] = input->argi_intentsitateak[i];
  }
  return true;
}

mezuak__msg__IslatutakoArgia *
mezuak__msg__IslatutakoArgia__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mezuak__msg__IslatutakoArgia * msg = (mezuak__msg__IslatutakoArgia *)allocator.allocate(sizeof(mezuak__msg__IslatutakoArgia), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mezuak__msg__IslatutakoArgia));
  bool success = mezuak__msg__IslatutakoArgia__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mezuak__msg__IslatutakoArgia__destroy(mezuak__msg__IslatutakoArgia * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mezuak__msg__IslatutakoArgia__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mezuak__msg__IslatutakoArgia__Sequence__init(mezuak__msg__IslatutakoArgia__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mezuak__msg__IslatutakoArgia * data = NULL;

  if (size) {
    data = (mezuak__msg__IslatutakoArgia *)allocator.zero_allocate(size, sizeof(mezuak__msg__IslatutakoArgia), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mezuak__msg__IslatutakoArgia__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mezuak__msg__IslatutakoArgia__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mezuak__msg__IslatutakoArgia__Sequence__fini(mezuak__msg__IslatutakoArgia__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mezuak__msg__IslatutakoArgia__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mezuak__msg__IslatutakoArgia__Sequence *
mezuak__msg__IslatutakoArgia__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mezuak__msg__IslatutakoArgia__Sequence * array = (mezuak__msg__IslatutakoArgia__Sequence *)allocator.allocate(sizeof(mezuak__msg__IslatutakoArgia__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mezuak__msg__IslatutakoArgia__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mezuak__msg__IslatutakoArgia__Sequence__destroy(mezuak__msg__IslatutakoArgia__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mezuak__msg__IslatutakoArgia__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mezuak__msg__IslatutakoArgia__Sequence__are_equal(const mezuak__msg__IslatutakoArgia__Sequence * lhs, const mezuak__msg__IslatutakoArgia__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mezuak__msg__IslatutakoArgia__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mezuak__msg__IslatutakoArgia__Sequence__copy(
  const mezuak__msg__IslatutakoArgia__Sequence * input,
  mezuak__msg__IslatutakoArgia__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mezuak__msg__IslatutakoArgia);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mezuak__msg__IslatutakoArgia * data =
      (mezuak__msg__IslatutakoArgia *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mezuak__msg__IslatutakoArgia__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mezuak__msg__IslatutakoArgia__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mezuak__msg__IslatutakoArgia__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
