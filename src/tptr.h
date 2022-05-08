/*
This file contains the definitions of all public members of the `libtptr`
library. Please refer to the README for detailed documentation on each member
defined here.
*/

#ifndef TPTR_H_
#define TPTR_H_

#include <xerrh.h>

/*
An enum which stores the names of all datatypes which can be pointed-to by a
`tp_TypePtr`.
*/
typedef enum tp_TypeName;

/*
An opaque handle to a Typed-Pointer object. Objects of this type can store not
only a pointer to a data address, but also the type of data stored at that
address.
*/
typedef struct tp_TypePtr *tp_TypePtr;

/*
Delete an instance of `tp_TypePtr`.
*/
xe_Code tp_del(tp_TypePtr tptr);

/*
Write the raw pointer of `tptr` to `ret`.
*/
xe_Code tp_getptr(tp_TypePtr tptr, void *ret);

/*
Write the type name enum of `tptr` to `ret`.
*/
xe_Code tp_gettype(tp_TypePtr tptr, tp_TypeName *ret);

/*
Build a new instance of `tp_TypePtr` and write it to `ret`.

Returns `xe_MEM` if allocation of heap memory for the new instance fails.
*/
xe_Code tp_new(tp_TypeName type, void *rawptr, tp_TypePtr *ret);

#endif