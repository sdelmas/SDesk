
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = 
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/packetizer
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in packetizer_copy packetizer_mpegvideo packetizer_mpeg4video packetizer_mpeg4audio packetizer_h264; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in packetizer_copy packetizer_mpegvideo packetizer_mpeg4video packetizer_mpeg4audio packetizer_h264; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in packetizer_copy packetizer_mpegvideo packetizer_mpeg4video packetizer_mpeg4audio packetizer_h264; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The packetizer_copy plugin

if UNTRUE
Lpacketizer_copyp = libpacketizer_copy_plugin.a
Dpacketizer_copyp = libpacketizer_copy_plugin$(LIBEXT)
Lpacketizer_copyb = libpacketizer_copy.a
Lpacketizer_copypic = libpacketizer_copy_pic.a
endif

libpacketizer_copy_plugin_a_SOURCES = $(SOURCES_packetizer_copy)
libpacketizer_copy_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin packetizer_copy`
libpacketizer_copy_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin packetizer_copy`
libpacketizer_copy_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin packetizer_copy`

libpacketizer_copy_pic_a_SOURCES = $(SOURCES_packetizer_copy)
libpacketizer_copy_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic packetizer_copy`
libpacketizer_copy_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic packetizer_copy`
libpacketizer_copy_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic packetizer_copy`

libpacketizer_copy_a_SOURCES = $(SOURCES_packetizer_copy)
libpacketizer_copy_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin packetizer_copy`
libpacketizer_copy_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin packetizer_copy`
libpacketizer_copy_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin packetizer_copy`

libvlc_LIBRARIES += $(Lpacketizer_copyb) $(Lpacketizer_copypic)
libpacketizer_copy_DATA = $(Dpacketizer_copyp)

libpacketizer_copydir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lpacketizer_copyp)
libpacketizer_copy_plugin$(LIBEXT): $(libpacketizer_copy_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage packetizer_copy` in \
	  c++) echo $(CXXLINK) $(libpacketizer_copy_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_copy\` ; $(CXXLINK) $(libpacketizer_copy_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_copy` ;; \
	  objc) echo $(OBJCLINK) $(libpacketizer_copy_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_copy\` ; $(OBJCLINK) $(libpacketizer_copy_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_copy` ;; \
	  c|*) echo $(LINK) $(libpacketizer_copy_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_copy\` ; $(LINK) $(libpacketizer_copy_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_copy` ;; \
	esac


# The packetizer_mpegvideo plugin

if UNTRUE
Lpacketizer_mpegvideop = libpacketizer_mpegvideo_plugin.a
Dpacketizer_mpegvideop = libpacketizer_mpegvideo_plugin$(LIBEXT)
Lpacketizer_mpegvideob = libpacketizer_mpegvideo.a
Lpacketizer_mpegvideopic = libpacketizer_mpegvideo_pic.a
endif

libpacketizer_mpegvideo_plugin_a_SOURCES = $(SOURCES_packetizer_mpegvideo)
libpacketizer_mpegvideo_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin packetizer_mpegvideo`
libpacketizer_mpegvideo_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin packetizer_mpegvideo`
libpacketizer_mpegvideo_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin packetizer_mpegvideo`

libpacketizer_mpegvideo_pic_a_SOURCES = $(SOURCES_packetizer_mpegvideo)
libpacketizer_mpegvideo_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic packetizer_mpegvideo`
libpacketizer_mpegvideo_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic packetizer_mpegvideo`
libpacketizer_mpegvideo_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic packetizer_mpegvideo`

libpacketizer_mpegvideo_a_SOURCES = $(SOURCES_packetizer_mpegvideo)
libpacketizer_mpegvideo_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin packetizer_mpegvideo`
libpacketizer_mpegvideo_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin packetizer_mpegvideo`
libpacketizer_mpegvideo_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin packetizer_mpegvideo`

libvlc_LIBRARIES += $(Lpacketizer_mpegvideob) $(Lpacketizer_mpegvideopic)
libpacketizer_mpegvideo_DATA = $(Dpacketizer_mpegvideop)

libpacketizer_mpegvideodir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lpacketizer_mpegvideop)
libpacketizer_mpegvideo_plugin$(LIBEXT): $(libpacketizer_mpegvideo_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage packetizer_mpegvideo` in \
	  c++) echo $(CXXLINK) $(libpacketizer_mpegvideo_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_mpegvideo\` ; $(CXXLINK) $(libpacketizer_mpegvideo_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_mpegvideo` ;; \
	  objc) echo $(OBJCLINK) $(libpacketizer_mpegvideo_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_mpegvideo\` ; $(OBJCLINK) $(libpacketizer_mpegvideo_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_mpegvideo` ;; \
	  c|*) echo $(LINK) $(libpacketizer_mpegvideo_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_mpegvideo\` ; $(LINK) $(libpacketizer_mpegvideo_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_mpegvideo` ;; \
	esac


# The packetizer_mpeg4video plugin

if UNTRUE
Lpacketizer_mpeg4videop = libpacketizer_mpeg4video_plugin.a
Dpacketizer_mpeg4videop = libpacketizer_mpeg4video_plugin$(LIBEXT)
Lpacketizer_mpeg4videob = libpacketizer_mpeg4video.a
Lpacketizer_mpeg4videopic = libpacketizer_mpeg4video_pic.a
endif

libpacketizer_mpeg4video_plugin_a_SOURCES = $(SOURCES_packetizer_mpeg4video)
libpacketizer_mpeg4video_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin packetizer_mpeg4video`
libpacketizer_mpeg4video_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin packetizer_mpeg4video`
libpacketizer_mpeg4video_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin packetizer_mpeg4video`

libpacketizer_mpeg4video_pic_a_SOURCES = $(SOURCES_packetizer_mpeg4video)
libpacketizer_mpeg4video_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic packetizer_mpeg4video`
libpacketizer_mpeg4video_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic packetizer_mpeg4video`
libpacketizer_mpeg4video_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic packetizer_mpeg4video`

libpacketizer_mpeg4video_a_SOURCES = $(SOURCES_packetizer_mpeg4video)
libpacketizer_mpeg4video_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin packetizer_mpeg4video`
libpacketizer_mpeg4video_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin packetizer_mpeg4video`
libpacketizer_mpeg4video_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin packetizer_mpeg4video`

libvlc_LIBRARIES += $(Lpacketizer_mpeg4videob) $(Lpacketizer_mpeg4videopic)
libpacketizer_mpeg4video_DATA = $(Dpacketizer_mpeg4videop)

libpacketizer_mpeg4videodir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lpacketizer_mpeg4videop)
libpacketizer_mpeg4video_plugin$(LIBEXT): $(libpacketizer_mpeg4video_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage packetizer_mpeg4video` in \
	  c++) echo $(CXXLINK) $(libpacketizer_mpeg4video_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_mpeg4video\` ; $(CXXLINK) $(libpacketizer_mpeg4video_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_mpeg4video` ;; \
	  objc) echo $(OBJCLINK) $(libpacketizer_mpeg4video_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_mpeg4video\` ; $(OBJCLINK) $(libpacketizer_mpeg4video_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_mpeg4video` ;; \
	  c|*) echo $(LINK) $(libpacketizer_mpeg4video_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_mpeg4video\` ; $(LINK) $(libpacketizer_mpeg4video_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_mpeg4video` ;; \
	esac


# The packetizer_mpeg4audio plugin

if UNTRUE
Lpacketizer_mpeg4audiop = libpacketizer_mpeg4audio_plugin.a
Dpacketizer_mpeg4audiop = libpacketizer_mpeg4audio_plugin$(LIBEXT)
Lpacketizer_mpeg4audiob = libpacketizer_mpeg4audio.a
Lpacketizer_mpeg4audiopic = libpacketizer_mpeg4audio_pic.a
endif

libpacketizer_mpeg4audio_plugin_a_SOURCES = $(SOURCES_packetizer_mpeg4audio)
libpacketizer_mpeg4audio_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin packetizer_mpeg4audio`
libpacketizer_mpeg4audio_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin packetizer_mpeg4audio`
libpacketizer_mpeg4audio_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin packetizer_mpeg4audio`

libpacketizer_mpeg4audio_pic_a_SOURCES = $(SOURCES_packetizer_mpeg4audio)
libpacketizer_mpeg4audio_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic packetizer_mpeg4audio`
libpacketizer_mpeg4audio_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic packetizer_mpeg4audio`
libpacketizer_mpeg4audio_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic packetizer_mpeg4audio`

libpacketizer_mpeg4audio_a_SOURCES = $(SOURCES_packetizer_mpeg4audio)
libpacketizer_mpeg4audio_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin packetizer_mpeg4audio`
libpacketizer_mpeg4audio_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin packetizer_mpeg4audio`
libpacketizer_mpeg4audio_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin packetizer_mpeg4audio`

libvlc_LIBRARIES += $(Lpacketizer_mpeg4audiob) $(Lpacketizer_mpeg4audiopic)
libpacketizer_mpeg4audio_DATA = $(Dpacketizer_mpeg4audiop)

libpacketizer_mpeg4audiodir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lpacketizer_mpeg4audiop)
libpacketizer_mpeg4audio_plugin$(LIBEXT): $(libpacketizer_mpeg4audio_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage packetizer_mpeg4audio` in \
	  c++) echo $(CXXLINK) $(libpacketizer_mpeg4audio_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_mpeg4audio\` ; $(CXXLINK) $(libpacketizer_mpeg4audio_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_mpeg4audio` ;; \
	  objc) echo $(OBJCLINK) $(libpacketizer_mpeg4audio_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_mpeg4audio\` ; $(OBJCLINK) $(libpacketizer_mpeg4audio_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_mpeg4audio` ;; \
	  c|*) echo $(LINK) $(libpacketizer_mpeg4audio_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_mpeg4audio\` ; $(LINK) $(libpacketizer_mpeg4audio_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_mpeg4audio` ;; \
	esac


# The packetizer_h264 plugin

if UNTRUE
Lpacketizer_h264p = libpacketizer_h264_plugin.a
Dpacketizer_h264p = libpacketizer_h264_plugin$(LIBEXT)
Lpacketizer_h264b = libpacketizer_h264.a
Lpacketizer_h264pic = libpacketizer_h264_pic.a
endif

libpacketizer_h264_plugin_a_SOURCES = $(SOURCES_packetizer_h264)
libpacketizer_h264_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin packetizer_h264`
libpacketizer_h264_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin packetizer_h264`
libpacketizer_h264_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin packetizer_h264`

libpacketizer_h264_pic_a_SOURCES = $(SOURCES_packetizer_h264)
libpacketizer_h264_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic packetizer_h264`
libpacketizer_h264_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic packetizer_h264`
libpacketizer_h264_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic packetizer_h264`

libpacketizer_h264_a_SOURCES = $(SOURCES_packetizer_h264)
libpacketizer_h264_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin packetizer_h264`
libpacketizer_h264_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin packetizer_h264`
libpacketizer_h264_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin packetizer_h264`

libvlc_LIBRARIES += $(Lpacketizer_h264b) $(Lpacketizer_h264pic)
libpacketizer_h264_DATA = $(Dpacketizer_h264p)

libpacketizer_h264dir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lpacketizer_h264p)
libpacketizer_h264_plugin$(LIBEXT): $(libpacketizer_h264_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage packetizer_h264` in \
	  c++) echo $(CXXLINK) $(libpacketizer_h264_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_h264\` ; $(CXXLINK) $(libpacketizer_h264_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_h264` ;; \
	  objc) echo $(OBJCLINK) $(libpacketizer_h264_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_h264\` ; $(OBJCLINK) $(libpacketizer_h264_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_h264` ;; \
	  c|*) echo $(LINK) $(libpacketizer_h264_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin packetizer_h264\` ; $(LINK) $(libpacketizer_h264_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin packetizer_h264` ;; \
	esac


