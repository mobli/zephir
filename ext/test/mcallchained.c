
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"


/**
 * Chained method calls
 */
ZEPHIR_INIT_CLASS(Test_McallChained) {

	ZEPHIR_REGISTER_CLASS(Test, McallChained, test, mcallchained, test_mcallchained_method_entry, 0);

	zend_declare_property_null(test_mcallchained_ce, SL("temp"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Test_McallChained, testMethod1) {


	RETURN_THISW();

}

PHP_METHOD(Test_McallChained, testMethod2) {


	RETURN_THISW();

}

PHP_METHOD(Test_McallChained, testMethod3) {


	RETURN_THISW();

}

PHP_METHOD(Test_McallChained, testChained1) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "testmethod1");
	zephir_call_method(return_value, _0, "testmethod2");
	RETURN_MM();

}

PHP_METHOD(Test_McallChained, testChained2) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "testmethod1");
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, _0, "testmethod3");
	zephir_call_method(return_value, _1, "testmethod2");
	RETURN_MM();

}

PHP_METHOD(Test_McallChained, testChained3) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_call_method(_0, this_ptr, "testmethod3");
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, _0, "testmethod2");
	zephir_call_method(return_value, _1, "testmethod1");
	RETURN_MM();

}

PHP_METHOD(Test_McallChained, testChained4) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	zephir_update_property_this(this_ptr, SL("temp"), this_ptr TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("temp"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_call_method(_1, _0, "testmethod1");
	zephir_call_method(return_value, _1, "testmethod2");
	RETURN_MM();

}

