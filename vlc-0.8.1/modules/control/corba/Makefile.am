
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = 
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/control
include Modules.am

if BUILD_MOZILLA
if HAVE_WIN32
# There's no need for pic code on win32 so get rid of this to substantially
# reduce the compilation time.
pic = no
endif
else
pic = no
endif

clean-local:
	-rm -f *.a *.so *.dll *.sl *.dylib

all: all-modules
all-modules:
	@set fnord $$MAKEFLAGS; amf=$$2; targets=`\
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in corba; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in corba; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in corba; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The corba plugin

clean-local: clean-corba
clean-corba:
	-test -z "$(nodist_SOURCES_corba)" || rm -f $(nodist_SOURCES_corba)

if UNTRUE
Lcorbap = libcorba_plugin.a
Dcorbap = libcorba_plugin$(LIBEXT)
Lcorbab = libcorba.a
Lcorbapic = libcorba_pic.a
Bcorba = $(nodist_SOURCES_corba)
endif

BUILT_SOURCES += $(Bcorba)
libcorba_plugin_a_SOURCES = $(SOURCES_corba)
nodist_libcorba_plugin_a_SOURCES = $(nodist_SOURCES_corba)
libcorba_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin corba`
libcorba_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin corba`
libcorba_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin corba`

libcorba_pic_a_SOURCES = $(SOURCES_corba)
nodist_libcorba_pic_a_SOURCES = $(nodist_SOURCES_corba)
libcorba_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic corba`
libcorba_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic corba`
libcorba_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic corba`

libcorba_a_SOURCES = $(SOURCES_corba)
nodist_libcorba_a_SOURCES = $(nodist_SOURCES_corba)
libcorba_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin corba`
libcorba_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin corba`
libcorba_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin corba`

libvlc_LIBRARIES += $(Lcorbab) $(Lcorbapic)
libcorba_DATA = $(Dcorbap)

libcorbadir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lcorbap)
libcorba_plugin$(LIBEXT): $(libcorba_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage corba` in \
	  c++) echo $(CXXLINK) $(libcorba_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin corba\` ; $(CXXLINK) $(libcorba_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin corba` ;; \
	  objc) echo $(OBJCLINK) $(libcorba_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin corba\` ; $(OBJCLINK) $(libcorba_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin corba` ;; \
	  c|*) echo $(LINK) $(libcorba_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin corba\` ; $(LINK) $(libcorba_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin corba` ;; \
	esac


