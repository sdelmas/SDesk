
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in vcdx; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in vcdx; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in vcdx; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The vcdx plugin

if UNTRUE
Lvcdxp = libvcdx_plugin.a
Dvcdxp = libvcdx_plugin$(LIBEXT)
Lvcdxb = libvcdx.a
Lvcdxpic = libvcdx_pic.a
endif

libvcdx_plugin_a_SOURCES = $(SOURCES_vcdx)
libvcdx_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin vcdx`
libvcdx_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin vcdx`
libvcdx_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin vcdx`

libvcdx_pic_a_SOURCES = $(SOURCES_vcdx)
libvcdx_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic vcdx`
libvcdx_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic vcdx`
libvcdx_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic vcdx`

libvcdx_a_SOURCES = $(SOURCES_vcdx)
libvcdx_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin vcdx`
libvcdx_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin vcdx`
libvcdx_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin vcdx`

libvlc_LIBRARIES += $(Lvcdxb) $(Lvcdxpic)
libvcdx_DATA = $(Dvcdxp)

libvcdxdir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lvcdxp)
libvcdx_plugin$(LIBEXT): $(libvcdx_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage vcdx` in \
	  c++) echo $(CXXLINK) $(libvcdx_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin vcdx\` ; $(CXXLINK) $(libvcdx_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin vcdx` ;; \
	  objc) echo $(OBJCLINK) $(libvcdx_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin vcdx\` ; $(OBJCLINK) $(libvcdx_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin vcdx` ;; \
	  c|*) echo $(LINK) $(libvcdx_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin vcdx\` ; $(LINK) $(libvcdx_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin vcdx` ;; \
	esac


