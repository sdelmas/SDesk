
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = 
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/access
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in cddax; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in cddax; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in cddax; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The cddax plugin

if UNTRUE
Lcddaxp = libcddax_plugin.a
Dcddaxp = libcddax_plugin$(LIBEXT)
Lcddaxb = libcddax.a
Lcddaxpic = libcddax_pic.a
endif

libcddax_plugin_a_SOURCES = $(SOURCES_cddax)
libcddax_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin cddax`
libcddax_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin cddax`
libcddax_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin cddax`

libcddax_pic_a_SOURCES = $(SOURCES_cddax)
libcddax_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic cddax`
libcddax_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic cddax`
libcddax_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic cddax`

libcddax_a_SOURCES = $(SOURCES_cddax)
libcddax_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin cddax`
libcddax_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin cddax`
libcddax_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin cddax`

libvlc_LIBRARIES += $(Lcddaxb) $(Lcddaxpic)
libcddax_DATA = $(Dcddaxp)

libcddaxdir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lcddaxp)
libcddax_plugin$(LIBEXT): $(libcddax_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage cddax` in \
	  c++) echo $(CXXLINK) $(libcddax_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin cddax\` ; $(CXXLINK) $(libcddax_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin cddax` ;; \
	  objc) echo $(OBJCLINK) $(libcddax_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin cddax\` ; $(OBJCLINK) $(libcddax_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin cddax` ;; \
	  c|*) echo $(LINK) $(libcddax_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin cddax\` ; $(LINK) $(libcddax_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin cddax` ;; \
	esac


