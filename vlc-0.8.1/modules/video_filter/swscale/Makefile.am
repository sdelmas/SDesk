
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = 
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/video_filter
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in swscale; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in swscale; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in swscale; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The swscale plugin

if UNTRUE
Lswscalep = libswscale_plugin.a
Dswscalep = libswscale_plugin$(LIBEXT)
Lswscaleb = libswscale.a
Lswscalepic = libswscale_pic.a
endif

libswscale_plugin_a_SOURCES = $(SOURCES_swscale)
libswscale_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin swscale`
libswscale_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin swscale`
libswscale_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin swscale`

libswscale_pic_a_SOURCES = $(SOURCES_swscale)
libswscale_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic swscale`
libswscale_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic swscale`
libswscale_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic swscale`

libswscale_a_SOURCES = $(SOURCES_swscale)
libswscale_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin swscale`
libswscale_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin swscale`
libswscale_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin swscale`

libvlc_LIBRARIES += $(Lswscaleb) $(Lswscalepic)
libswscale_DATA = $(Dswscalep)

libswscaledir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lswscalep)
libswscale_plugin$(LIBEXT): $(libswscale_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage swscale` in \
	  c++) echo $(CXXLINK) $(libswscale_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin swscale\` ; $(CXXLINK) $(libswscale_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin swscale` ;; \
	  objc) echo $(OBJCLINK) $(libswscale_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin swscale\` ; $(OBJCLINK) $(libswscale_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin swscale` ;; \
	  c|*) echo $(LINK) $(libswscale_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin swscale\` ; $(LINK) $(libswscale_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin swscale` ;; \
	esac


