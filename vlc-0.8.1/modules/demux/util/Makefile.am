
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = 
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/demux
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in id3 id3tag; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in id3 id3tag; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in id3 id3tag; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The id3 plugin

if UNTRUE
Lid3p = libid3_plugin.a
Did3p = libid3_plugin$(LIBEXT)
Lid3b = libid3.a
Lid3pic = libid3_pic.a
endif

libid3_plugin_a_SOURCES = $(SOURCES_id3)
libid3_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin id3`
libid3_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin id3`
libid3_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin id3`

libid3_pic_a_SOURCES = $(SOURCES_id3)
libid3_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic id3`
libid3_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic id3`
libid3_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic id3`

libid3_a_SOURCES = $(SOURCES_id3)
libid3_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin id3`
libid3_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin id3`
libid3_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin id3`

libvlc_LIBRARIES += $(Lid3b) $(Lid3pic)
libid3_DATA = $(Did3p)

libid3dir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lid3p)
libid3_plugin$(LIBEXT): $(libid3_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage id3` in \
	  c++) echo $(CXXLINK) $(libid3_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin id3\` ; $(CXXLINK) $(libid3_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin id3` ;; \
	  objc) echo $(OBJCLINK) $(libid3_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin id3\` ; $(OBJCLINK) $(libid3_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin id3` ;; \
	  c|*) echo $(LINK) $(libid3_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin id3\` ; $(LINK) $(libid3_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin id3` ;; \
	esac


# The id3tag plugin

if UNTRUE
Lid3tagp = libid3tag_plugin.a
Did3tagp = libid3tag_plugin$(LIBEXT)
Lid3tagb = libid3tag.a
Lid3tagpic = libid3tag_pic.a
endif

libid3tag_plugin_a_SOURCES = $(SOURCES_id3tag)
libid3tag_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin id3tag`
libid3tag_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin id3tag`
libid3tag_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin id3tag`

libid3tag_pic_a_SOURCES = $(SOURCES_id3tag)
libid3tag_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic id3tag`
libid3tag_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic id3tag`
libid3tag_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic id3tag`

libid3tag_a_SOURCES = $(SOURCES_id3tag)
libid3tag_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin id3tag`
libid3tag_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin id3tag`
libid3tag_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin id3tag`

libvlc_LIBRARIES += $(Lid3tagb) $(Lid3tagpic)
libid3tag_DATA = $(Did3tagp)

libid3tagdir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lid3tagp)
libid3tag_plugin$(LIBEXT): $(libid3tag_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage id3tag` in \
	  c++) echo $(CXXLINK) $(libid3tag_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin id3tag\` ; $(CXXLINK) $(libid3tag_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin id3tag` ;; \
	  objc) echo $(OBJCLINK) $(libid3tag_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin id3tag\` ; $(OBJCLINK) $(libid3tag_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin id3tag` ;; \
	  c|*) echo $(LINK) $(libid3tag_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin id3tag\` ; $(LINK) $(libid3tag_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin id3tag` ;; \
	esac


