#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_mapi.h"
#include "mapi_session.h"

static zend_function_entry mapi_session_class_functions[] = {
  PHP_ME(MAPISession, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  // PHP_ME(MAPISession, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
  PHP_ME(MAPISession, login, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(MAPISession, folders, NULL, ZEND_ACC_PUBLIC)
  { NULL, NULL, NULL }
};

void MAPISessionRegisterClass()
{
  zend_class_entry ce;
  INIT_CLASS_ENTRY(ce, "MAPISession", mapi_session_class_functions);
  zend_register_internal_class(&ce TSRMLS_CC);
}

PHP_METHOD(MAPISession, __construct)
{
  zval* profileObject;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "o",
                            &profileObject) == FAILURE ) {
    RETURN_NULL();
  }

  if (strncmp(Z_OBJCE_P(profileObject)->name, "MAPIProfile", sizeof("MAPIProfile")+1) != 0) {
    php_error(E_ERROR, "The object must be of the class MAPIProfile");
  }

}

PHP_METHOD(MAPISession, login)
{
}

PHP_METHOD(MAPISession, folders)
{
}
