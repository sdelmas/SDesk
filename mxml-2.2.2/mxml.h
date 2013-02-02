/*
 * "$Id: mxml.h 184 2005-01-29 07:21:44Z mike $"
 *
 * Header file for Mini-XML, a small XML-like file parsing library.
 *
 * Copyright 2003-2005 by Michael Sweet.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/*
 * Prevent multiple inclusion...
 */

#ifndef _mxml_h_
#  define _mxml_h_

/*
 * Include necessary headers...
 */

#  include <stdio.h>
#  include <stdlib.h>
#  include <string.h>
#  include <ctype.h>
#  include <errno.h>


/*
 * Constants...
 */

#  define MXML_WRAP		72	/* Wrap XML output at this column position */
#  define MXML_TAB		8	/* Tabs every N columns */

#  define MXML_NO_CALLBACK	0	/* Don't use a type callback */
#  define MXML_INTEGER_CALLBACK	mxml_integer_cb
					/* Treat all data as integers */
#  define MXML_OPAQUE_CALLBACK	mxml_opaque_cb
					/* Treat all data as opaque */
#  define MXML_REAL_CALLBACK	mxml_real_cb
					/* Treat all data as real numbers */
#  define MXML_TEXT_CALLBACK	0	/* Treat all data as text */

#  define MXML_NO_PARENT	0	/* No parent for the node */

#  define MXML_DESCEND		1	/* Descend when finding/walking */
#  define MXML_NO_DESCEND	0	/* Don't descend when finding/walking */
#  define MXML_DESCEND_FIRST	-1	/* Descend for first find */

#  define MXML_WS_BEFORE_OPEN	0	/* Callback for before open tag */
#  define MXML_WS_AFTER_OPEN	1	/* Callback for after open tag */
#  define MXML_WS_BEFORE_CLOSE	2	/* Callback for before close tag */
#  define MXML_WS_AFTER_CLOSE	3	/* Callback for after close tag */

#  define MXML_ADD_BEFORE	0	/* Add node before specified node */
#  define MXML_ADD_AFTER	1	/* Add node after specified node */
#  define MXML_ADD_TO_PARENT	NULL	/* Add node relative to parent */


/*
 * Data types...
 */

typedef enum mxml_type_e		/**** The XML node type. ****/
{
  MXML_ELEMENT,				/* XML element with attributes */
  MXML_INTEGER,				/* Integer value */
  MXML_OPAQUE,				/* Opaque string */
  MXML_REAL,				/* Real value */
  MXML_TEXT,				/* Text fragment */
  MXML_CUSTOM				/* Custom data */
} mxml_type_t;

typedef struct mxml_attr_s		/**** An XML element attribute value. ****/
{
  char			*name;		/* Attribute name */
  char			*value;		/* Attribute value */
} mxml_attr_t;

typedef struct mxml_value_s		/**** An XML element value. ****/
{
  char			*name;		/* Name of element */
  int			num_attrs;	/* Number of attributes */
  mxml_attr_t		*attrs;		/* Attributes */
} mxml_element_t;

typedef struct mxml_text_s		/**** An XML text value. ****/
{
  int			whitespace;	/* Leading whitespace? */
  char			*string;	/* Fragment string */
} mxml_text_t;

typedef struct mxml_custom_s		/**** An XML custom value. ****/
{
  void			*data;		/* Pointer to (allocated) custom data */
  void			(*destroy)(void *);
					/* Pointer to destructor function */
} mxml_custom_t;

typedef union mxml_value_u		/**** An XML node value. ****/
{
  mxml_element_t	element;	/* Element */
  int			integer;	/* Integer number */
  char			*opaque;	/* Opaque string */
  double		real;		/* Real number */
  mxml_text_t		text;		/* Text fragment */
  mxml_custom_t		custom;		/* Custom data */
} mxml_value_t;

typedef struct mxml_node_s		/**** An XML node. ****/
{
  mxml_type_t		type;		/* Node type */
  struct mxml_node_s	*next;		/* Next node under same parent */
  struct mxml_node_s	*prev;		/* Previous node under same parent */
  struct mxml_node_s	*parent;	/* Parent node */
  struct mxml_node_s	*child;		/* First child node */
  struct mxml_node_s	*last_child;	/* Last child node */
  mxml_value_t		value;		/* Node value */
} mxml_node_t;

typedef struct mxml_index_s		/**** An XML node index. ****/
{
  char			*attr;		/* Attribute used for indexing or NULL */
  int			num_nodes;	/* Number of nodes in index */
  int			alloc_nodes;	/* Allocated nodes in index */
  int			cur_node;	/* Current node */
  mxml_node_t		**nodes;	/* Node array */
} mxml_index_t;

typedef int (*mxml_custom_load_cb_t)(mxml_node_t *, const char *);
					/**** Custom data load callback function ****/

typedef char *(*mxml_custom_save_cb_t)(mxml_node_t *);  
					/**** Custom data save callback function ****/


/*
 * C++ support...
 */

#  ifdef __cplusplus
extern "C" {
#  endif /* __cplusplus */

/*
 * Prototypes...
 */

extern void		mxmlAdd(mxml_node_t *parent, int where,
			        mxml_node_t *child, mxml_node_t *node);
extern void		mxmlDelete(mxml_node_t *node);
extern const char	*mxmlElementGetAttr(mxml_node_t *node, const char *name);
extern void		mxmlElementSetAttr(mxml_node_t *node, const char *name,
			                   const char *value);
extern int		mxmlEntityAddCallback(int (*cb)(const char *name));
extern const char	*mxmlEntityGetName(int val);
extern int		mxmlEntityGetValue(const char *name);
extern void		mxmlEntityRemoveCallback(int (*cb)(const char *name));
extern mxml_node_t	*mxmlFindElement(mxml_node_t *node, mxml_node_t *top,
			                 const char *name, const char *attr,
					 const char *value, int descend);
extern void		mxmlIndexDelete(mxml_index_t *ind);
extern mxml_node_t	*mxmlIndexEnum(mxml_index_t *ind);
extern mxml_node_t	*mxmlIndexFind(mxml_index_t *ind,
			               const char *element,
			               const char *value);
extern mxml_index_t	*mxmlIndexNew(mxml_node_t *node, const char *element,
			              const char *attr);
extern mxml_node_t	*mxmlIndexReset(mxml_index_t *ind);
extern mxml_node_t	*mxmlLoadFd(mxml_node_t *top, int fd,
			            mxml_type_t (*cb)(mxml_node_t *));
extern mxml_node_t	*mxmlLoadFile(mxml_node_t *top, FILE *fp,
			              mxml_type_t (*cb)(mxml_node_t *));
extern mxml_node_t	*mxmlLoadString(mxml_node_t *top, const char *s,
			                mxml_type_t (*cb)(mxml_node_t *));
extern mxml_node_t	*mxmlNewCustom(mxml_node_t *parent, void *data,
			               void (*destroy)(void *));
extern mxml_node_t	*mxmlNewElement(mxml_node_t *parent, const char *name);
extern mxml_node_t	*mxmlNewInteger(mxml_node_t *parent, int integer);
extern mxml_node_t	*mxmlNewOpaque(mxml_node_t *parent, const char *opaque);
extern mxml_node_t	*mxmlNewReal(mxml_node_t *parent, double real);
extern mxml_node_t	*mxmlNewText(mxml_node_t *parent, int whitespace,
			             const char *string);
extern mxml_node_t	*mxmlNewTextf(mxml_node_t *parent, int whitespace,
			              const char *format, ...)
#    ifdef __GNUC__
__attribute__ ((__format__ (__printf__, 3, 4)))
#    endif /* __GNUC__ */
;
extern void		mxmlRemove(mxml_node_t *node);
extern char		*mxmlSaveAllocString(mxml_node_t *node,
			        	     const char *(*cb)(mxml_node_t *, int));
extern int		mxmlSaveFd(mxml_node_t *node, int fd,
			           const char *(*cb)(mxml_node_t *, int));
extern int		mxmlSaveFile(mxml_node_t *node, FILE *fp,
			             const char *(*cb)(mxml_node_t *, int));
extern int		mxmlSaveString(mxml_node_t *node, char *buffer,
			               int bufsize,
			               const char *(*cb)(mxml_node_t *, int));
extern int		mxmlSetCustom(mxml_node_t *node, void *data,
			              void (*destroy)(void *));
extern void		mxmlSetCustomHandlers(mxml_custom_load_cb_t load,
			                      mxml_custom_save_cb_t save);
extern int		mxmlSetElement(mxml_node_t *node, const char *name);
extern void		mxmlSetErrorCallback(void (*cb)(const char *));
extern int		mxmlSetInteger(mxml_node_t *node, int integer);
extern int		mxmlSetOpaque(mxml_node_t *node, const char *opaque);
extern int		mxmlSetReal(mxml_node_t *node, double real);
extern int		mxmlSetText(mxml_node_t *node, int whitespace,
			            const char *string);
extern int		mxmlSetTextf(mxml_node_t *node, int whitespace,
			             const char *format, ...)
#    ifdef __GNUC__
__attribute__ ((__format__ (__printf__, 3, 4)))
#    endif /* __GNUC__ */
;
extern mxml_node_t	*mxmlWalkNext(mxml_node_t *node, mxml_node_t *top,
			              int descend);
extern mxml_node_t	*mxmlWalkPrev(mxml_node_t *node, mxml_node_t *top,
			              int descend);


/*
 * Private functions...
 */

extern void		mxml_error(const char *format, ...);
extern mxml_type_t	mxml_integer_cb(mxml_node_t *node);
extern mxml_type_t	mxml_opaque_cb(mxml_node_t *node);
extern mxml_type_t	mxml_real_cb(mxml_node_t *node);


/*
 * C++ support...
 */

#  ifdef __cplusplus
}
#  endif /* __cplusplus */
#endif /* !_mxml_h_ */


/*
 * End of "$Id: mxml.h 184 2005-01-29 07:21:44Z mike $".
 */
