
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = 
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/stream_out
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in stream_out_transrate; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in stream_out_transrate; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in stream_out_transrate; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The stream_out_transrate plugin

if UNTRUE
Lstream_out_transratep = libstream_out_transrate_plugin.a
Dstream_out_transratep = libstream_out_transrate_plugin$(LIBEXT)
Lstream_out_transrateb = libstream_out_transrate.a
Lstream_out_transratepic = libstream_out_transrate_pic.a
endif

libstream_out_transrate_plugin_a_SOURCES = $(SOURCES_stream_out_transrate)
libstream_out_transrate_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin stream_out_transrate`
libstream_out_transrate_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin stream_out_transrate`
libstream_out_transrate_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin stream_out_transrate`

libstream_out_transrate_pic_a_SOURCES = $(SOURCES_stream_out_transrate)
libstream_out_transrate_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic stream_out_transrate`
libstream_out_transrate_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic stream_out_transrate`
libstream_out_transrate_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic stream_out_transrate`

libstream_out_transrate_a_SOURCES = $(SOURCES_stream_out_transrate)
libstream_out_transrate_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin stream_out_transrate`
libstream_out_transrate_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin stream_out_transrate`
libstream_out_transrate_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin stream_out_transrate`

libvlc_LIBRARIES += $(Lstream_out_transrateb) $(Lstream_out_transratepic)
libstream_out_transrate_DATA = $(Dstream_out_transratep)

libstream_out_transratedir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lstream_out_transratep)
libstream_out_transrate_plugin$(LIBEXT): $(libstream_out_transrate_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage stream_out_transrate` in \
	  c++) echo $(CXXLINK) $(libstream_out_transrate_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin stream_out_transrate\` ; $(CXXLINK) $(libstream_out_transrate_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin stream_out_transrate` ;; \
	  objc) echo $(OBJCLINK) $(libstream_out_transrate_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin stream_out_transrate\` ; $(OBJCLINK) $(libstream_out_transrate_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin stream_out_transrate` ;; \
	  c|*) echo $(LINK) $(libstream_out_transrate_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin stream_out_transrate\` ; $(LINK) $(libstream_out_transrate_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin stream_out_transrate` ;; \
	esac


