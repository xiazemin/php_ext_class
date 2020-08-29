dnl $Id$
dnl config.m4 for extension myClass

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

 PHP_ARG_WITH(myClass, for myClass support,
 Make sure that the comment is aligned:
 [  --with-myClass             Include myClass support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(myClass, whether to enable myClass support,
dnl Make sure that the comment is aligned:
[  --enable-myClass           Enable myClass support])

if test "$PHP_MYCLASS" != "no"; then
  dnl Write more examples of tests here...

  dnl # get library FOO build options from pkg-config output
  dnl AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
  dnl AC_MSG_CHECKING(for libfoo)
  dnl if test -x "$PKG_CONFIG" && $PKG_CONFIG --exists foo; then
  dnl   if $PKG_CONFIG foo --atleast-version 1.2.3; then
  dnl     LIBFOO_CFLAGS=`$PKG_CONFIG foo --cflags`
  dnl     LIBFOO_LIBDIR=`$PKG_CONFIG foo --libs`
  dnl     LIBFOO_VERSON=`$PKG_CONFIG foo --modversion`
  dnl     AC_MSG_RESULT(from pkgconfig: version $LIBFOO_VERSON)
  dnl   else
  dnl     AC_MSG_ERROR(system libfoo is too old: version 1.2.3 required)
  dnl   fi
  dnl else
  dnl   AC_MSG_ERROR(pkg-config not found)
  dnl fi
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBDIR, MYCLASS_SHARED_LIBADD)
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)

  dnl # --with-myClass -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/myClass.h"  # you most likely want to change this
  dnl if test -r $PHP_MYCLASS/$SEARCH_FOR; then # path given as parameter
  dnl   MYCLASS_DIR=$PHP_MYCLASS
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for myClass files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       MYCLASS_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$MYCLASS_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the myClass distribution])
  dnl fi

  dnl # --with-myClass -> add include path
  dnl PHP_ADD_INCLUDE($MYCLASS_DIR/include)

  dnl # --with-myClass -> check for lib and symbol presence
  dnl LIBNAME=myClass # you may want to change this
  dnl LIBSYMBOL=myClass # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $MYCLASS_DIR/$PHP_LIBDIR, MYCLASS_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_MYCLASSLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong myClass lib version or lib not found])
  dnl ],[
  dnl   -L$MYCLASS_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(MYCLASS_SHARED_LIBADD)

  PHP_NEW_EXTENSION(myClass, myClass.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
