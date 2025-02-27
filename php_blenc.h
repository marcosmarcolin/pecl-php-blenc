/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.0 of the PHP license,       |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_0.txt.                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: John Coggeshall <john@php.net>                               |
  |         Giuseppe Chiesa <gchiesa@php.net>							 |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_BLENC_H
#define PHP_BLENC_H

#if ZEND_MODULE_API_NO >= 20151012 && ZEND_MODULE_API_NO < 20200930
#define PHP_ZEND_ENGINE_7_0
#endif

#if ZEND_MODULE_API_NO >= 20200930
#define PHP_ZEND_ENGINE_8_0
#endif


#define PHP_BLENC_VERSION "1.1.4b"
#define BLENC_IDENT "BLENC"
#define BLENC_BUFSIZE 4092

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

extern zend_module_entry blenc_module_entry;
#define phpext_blenc_ptr &blenc_module_entry

#ifdef PHP_WIN32
#define PHP_BLENC_API __declspec(dllexport)
#else
#define PHP_BLENC_API
#endif

#ifdef ZTS
#include "TSRM.h"
#else
// These are removed on PHP 8.x and they are not available on Ubuntu 7.4 so just behave
// they are until PHP 7.x in wiped out of earth

#ifndef TSRMLS_C
#define TSRMLS_C
#endif

#ifndef TSRMLS_CC
#define TSRMLS_CC
#endif

#ifndef TSRMLS_D
#define TSRMLS_D
#endif

#ifndef TSRMLS_DC
#define TSRMLS_DC
#endif

#endif

PHP_MINIT_FUNCTION(blenc);
PHP_MSHUTDOWN_FUNCTION(blenc);
PHP_RINIT_FUNCTION(blenc);
PHP_MINFO_FUNCTION(blenc);

PHP_FUNCTION(blenc_encrypt);

typedef unsigned char b_byte;
typedef unsigned int  b_uint;

ZEND_BEGIN_MODULE_GLOBALS(blenc)
char *key_file;
char *decoded;
unsigned int decoded_len;
unsigned int index;
zend_bool keys_loaded;
zend_bool expired;
char *expire_date;
unsigned long expire_date_numerical;
ZEND_END_MODULE_GLOBALS(blenc)

size_t (*old_stream_reader)(void *, char *, size_t TSRMLS_DC);
void (*old_stream_closer)(void * TSRMLS_DC);
#ifdef PHP_ZEND_ENGINE_7_0
zend_op_array *(*zend_compile_file_old)(zend_file_handle *, int TSRMLS_DC);
#endif
#ifdef PHP_ZEND_ENGINE_8_0
zend_op_array *(*zend_compile_file_old)(zend_file_handle *, int type);
#endif
zend_op_array *blenc_compile(zend_file_handle *, int TSRMLS_DC);

static void php_blenc_make_md5(char *, void *, unsigned int TSRMLS_DC);
static char *php_blenc_file_to_mem(char * TSRMLS_DC);
static int php_blenc_load_keyhash(TSRMLS_D);

b_byte *php_blenc_encode(void *, unsigned char *, int, int * TSRMLS_DC);
b_byte *php_blenc_decode(void *, unsigned char *, int, int * TSRMLS_DC);
static unsigned char *php_blenc_gen_key(TSRMLS_D);
void _php_blenc_pefree_wrapper(void **);

#ifdef ZTS
#define BL_G(v) TSRMG(blenc_globals_id, zend_blenc_globals *, v)
#else
#define BL_G(v) (blenc_globals.v)
#endif

#endif	/* PHP_BLENC_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
