/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_myClass.h"

/* If you declare any globals in php_myClass.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(myClass)
*/
zend_class_entry *person_ce;

/* True global resources - no need for thread safety here */
static int le_myClass;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("myClass.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_myClass_globals, myClass_globals)
    STD_PHP_INI_ENTRY("myClass.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_myClass_globals, myClass_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_myClass_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_myClass_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "myClass", arg);

	RETURN_STR(strg);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/

PHP_METHOD(Person, __construct) {
php_printf("__construct called.");
}

PHP_METHOD(Person, __destruct) {
php_printf("__destruct called.<br/>");
}

PHP_METHOD(Person, getName) {
zval *self;
zval *name;
//
self = getThis();
//name = zend_read_property(Z_OBJCE_P(self), self, ZEND_STRL("_name"), 0 TSRMLS_CC);
//zval *length = zend_read_property(person_ce, self, ZEND_STRL("_name"), 0 TSRMLS_CC,&name);
name =zend_read_property(person_ce, self, ZEND_STRL("_name"), 0 TSRMLS_CC,NULL);
////RETURN_STRING(Z_STRVAL_P(name), 0);
//php_printf("%s",Z_STRVAL(name));
//php_printf("%d",Z_LVAL_P(length));
//RETURN_STRING(Z_STRVAL_P(&name));
RETURN_STRING(Z_STRVAL(*name));
//RETURN_NULL();
}

PHP_METHOD(Person, setName) {
//char *arg = NULL;
////int arg_len;
//size_t arg_len;
//zval *value, *self;
//if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
//WRONG_PARAM_COUNT;
//}
//self = getThis();
////MAKE_STD_ZVAL(value);
//
////ZVAL_STRINGL(value, arg, arg_len, 0);
//ZVAL_STRINGL(value, arg, arg_len);
//SEPARATE_ZVAL_TO_MAKE_IS_REF(&value);
//zend_update_property(Z_OBJCE_P(self), self, ZEND_STRL("_name"), value TSRMLS_CC);
//RETURN_TRUE;
//char *arg = NULL;
////int arg_len;
//size_t arg_len;
//if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
//WRONG_PARAM_COUNT;
//}

//zval *name
char  *name;
zval  *self;
size_t name_len;
self = getThis();
//if (zend_parse_method_parameters(ZEND_NUM_ARGS(), getThis(), "s",&name, &name_len) == FAILURE) {
//if(zend_parse_method_parameters(ZEND_NUM_ARGS(),self,"Os",&self,&name,&name_len,person_ce)==FAILURE){
if(zend_parse_parameters(ZEND_NUM_ARGS(),"s",&name,&name_len)==FAILURE){
return;
}

zval  _name;
php_printf(name);
ZVAL_STRING(&_name,name);
//array_init(_name);
zend_update_property(Z_OBJCE_P(self), self, ZEND_STRL("_name"), &_name TSRMLS_CC);
//RETURN_NULL();
RETURN_TRUE;
}

ZEND_BEGIN_ARG_INFO(arg_person_setname, 0)
ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()
const zend_function_entry myClass_functions[] = {
        PHP_ME(Person, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
        PHP_ME(Person, __destruct,  NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
        PHP_ME(Person, getName,     NULL, ZEND_ACC_PUBLIC)
        PHP_ME(Person, setName,     arg_person_setname, ZEND_ACC_PUBLIC)
        PHP_FE_END
        //{NULL, NULL, NULL} /* Must be the last line in myClass_functions[] */
};
/* {{{ php_myClass_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_myClass_init_globals(zend_myClass_globals *myClass_globals)
{
	myClass_globals->global_value = 0;
	myClass_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(myClass)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	zend_class_entry person;
	INIT_CLASS_ENTRY(person, "Person", myClass_functions);
	//person_ce = zend_register_internal_class_ex(&person, NULL, NULL TSRMLS_CC);
	person_ce = zend_register_internal_class_ex(&person, NULL TSRMLS_CC);

	zend_declare_property_null(person_ce, ZEND_STRL("_name"), ZEND_ACC_PRIVATE TSRMLS_CC);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(myClass)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(myClass)
{
#if defined(COMPILE_DL_MYCLASS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(myClass)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(myClass)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "myClass support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ myClass_functions[]
 *
 * Every user visible function must have an entry in myClass_functions[].
 */

//const zend_function_entry myClass_functions[] = {
//	PHP_FE(confirm_myClass_compiled,	NULL)		/* For testing, remove later. */
//	PHP_FE_END	/* Must be the last line in myClass_functions[] */
//};

/* }}} */

/* {{{ myClass_module_entry
 */
zend_module_entry myClass_module_entry = {
	STANDARD_MODULE_HEADER,
	"myClass",
	myClass_functions,
	PHP_MINIT(myClass),
	PHP_MSHUTDOWN(myClass),
	PHP_RINIT(myClass),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(myClass),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(myClass),
	PHP_MYCLASS_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_MYCLASS
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(myClass)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
