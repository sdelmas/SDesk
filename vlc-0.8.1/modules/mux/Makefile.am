
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = mpeg
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/mux
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in mux_dummy mux_avi mux_ogg mux_mp4 mux_asf mux_wav mux_mpjpeg; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in mux_dummy mux_avi mux_ogg mux_mp4 mux_asf mux_wav mux_mpjpeg; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in mux_dummy mux_avi mux_ogg mux_mp4 mux_asf mux_wav mux_mpjpeg; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The mux_dummy plugin

if UNTRUE
Lmux_dummyp = libmux_dummy_plugin.a
Dmux_dummyp = libmux_dummy_plugin$(LIBEXT)
Lmux_dummyb = libmux_dummy.a
Lmux_dummypic = libmux_dummy_pic.a
endif

libmux_dummy_plugin_a_SOURCES = $(SOURCES_mux_dummy)
libmux_dummy_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin mux_dummy`
libmux_dummy_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin mux_dummy`
libmux_dummy_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin mux_dummy`

libmux_dummy_pic_a_SOURCES = $(SOURCES_mux_dummy)
libmux_dummy_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic mux_dummy`
libmux_dummy_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic mux_dummy`
libmux_dummy_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic mux_dummy`

libmux_dummy_a_SOURCES = $(SOURCES_mux_dummy)
libmux_dummy_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin mux_dummy`
libmux_dummy_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin mux_dummy`
libmux_dummy_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin mux_dummy`

libvlc_LIBRARIES += $(Lmux_dummyb) $(Lmux_dummypic)
libmux_dummy_DATA = $(Dmux_dummyp)

libmux_dummydir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lmux_dummyp)
libmux_dummy_plugin$(LIBEXT): $(libmux_dummy_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage mux_dummy` in \
	  c++) echo $(CXXLINK) $(libmux_dummy_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_dummy\` ; $(CXXLINK) $(libmux_dummy_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_dummy` ;; \
	  objc) echo $(OBJCLINK) $(libmux_dummy_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_dummy\` ; $(OBJCLINK) $(libmux_dummy_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_dummy` ;; \
	  c|*) echo $(LINK) $(libmux_dummy_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_dummy\` ; $(LINK) $(libmux_dummy_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_dummy` ;; \
	esac


# The mux_avi plugin

if UNTRUE
Lmux_avip = libmux_avi_plugin.a
Dmux_avip = libmux_avi_plugin$(LIBEXT)
Lmux_avib = libmux_avi.a
Lmux_avipic = libmux_avi_pic.a
endif

libmux_avi_plugin_a_SOURCES = $(SOURCES_mux_avi)
libmux_avi_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin mux_avi`
libmux_avi_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin mux_avi`
libmux_avi_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin mux_avi`

libmux_avi_pic_a_SOURCES = $(SOURCES_mux_avi)
libmux_avi_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic mux_avi`
libmux_avi_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic mux_avi`
libmux_avi_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic mux_avi`

libmux_avi_a_SOURCES = $(SOURCES_mux_avi)
libmux_avi_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin mux_avi`
libmux_avi_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin mux_avi`
libmux_avi_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin mux_avi`

libvlc_LIBRARIES += $(Lmux_avib) $(Lmux_avipic)
libmux_avi_DATA = $(Dmux_avip)

libmux_avidir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lmux_avip)
libmux_avi_plugin$(LIBEXT): $(libmux_avi_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage mux_avi` in \
	  c++) echo $(CXXLINK) $(libmux_avi_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_avi\` ; $(CXXLINK) $(libmux_avi_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_avi` ;; \
	  objc) echo $(OBJCLINK) $(libmux_avi_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_avi\` ; $(OBJCLINK) $(libmux_avi_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_avi` ;; \
	  c|*) echo $(LINK) $(libmux_avi_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_avi\` ; $(LINK) $(libmux_avi_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_avi` ;; \
	esac


# The mux_ogg plugin

if UNTRUE
Lmux_oggp = libmux_ogg_plugin.a
Dmux_oggp = libmux_ogg_plugin$(LIBEXT)
Lmux_oggb = libmux_ogg.a
Lmux_oggpic = libmux_ogg_pic.a
endif

libmux_ogg_plugin_a_SOURCES = $(SOURCES_mux_ogg)
libmux_ogg_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin mux_ogg`
libmux_ogg_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin mux_ogg`
libmux_ogg_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin mux_ogg`

libmux_ogg_pic_a_SOURCES = $(SOURCES_mux_ogg)
libmux_ogg_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic mux_ogg`
libmux_ogg_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic mux_ogg`
libmux_ogg_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic mux_ogg`

libmux_ogg_a_SOURCES = $(SOURCES_mux_ogg)
libmux_ogg_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin mux_ogg`
libmux_ogg_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin mux_ogg`
libmux_ogg_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin mux_ogg`

libvlc_LIBRARIES += $(Lmux_oggb) $(Lmux_oggpic)
libmux_ogg_DATA = $(Dmux_oggp)

libmux_oggdir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lmux_oggp)
libmux_ogg_plugin$(LIBEXT): $(libmux_ogg_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage mux_ogg` in \
	  c++) echo $(CXXLINK) $(libmux_ogg_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_ogg\` ; $(CXXLINK) $(libmux_ogg_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_ogg` ;; \
	  objc) echo $(OBJCLINK) $(libmux_ogg_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_ogg\` ; $(OBJCLINK) $(libmux_ogg_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_ogg` ;; \
	  c|*) echo $(LINK) $(libmux_ogg_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_ogg\` ; $(LINK) $(libmux_ogg_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_ogg` ;; \
	esac


# The mux_mp4 plugin

if UNTRUE
Lmux_mp4p = libmux_mp4_plugin.a
Dmux_mp4p = libmux_mp4_plugin$(LIBEXT)
Lmux_mp4b = libmux_mp4.a
Lmux_mp4pic = libmux_mp4_pic.a
endif

libmux_mp4_plugin_a_SOURCES = $(SOURCES_mux_mp4)
libmux_mp4_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin mux_mp4`
libmux_mp4_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin mux_mp4`
libmux_mp4_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin mux_mp4`

libmux_mp4_pic_a_SOURCES = $(SOURCES_mux_mp4)
libmux_mp4_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic mux_mp4`
libmux_mp4_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic mux_mp4`
libmux_mp4_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic mux_mp4`

libmux_mp4_a_SOURCES = $(SOURCES_mux_mp4)
libmux_mp4_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin mux_mp4`
libmux_mp4_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin mux_mp4`
libmux_mp4_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin mux_mp4`

libvlc_LIBRARIES += $(Lmux_mp4b) $(Lmux_mp4pic)
libmux_mp4_DATA = $(Dmux_mp4p)

libmux_mp4dir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lmux_mp4p)
libmux_mp4_plugin$(LIBEXT): $(libmux_mp4_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage mux_mp4` in \
	  c++) echo $(CXXLINK) $(libmux_mp4_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_mp4\` ; $(CXXLINK) $(libmux_mp4_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_mp4` ;; \
	  objc) echo $(OBJCLINK) $(libmux_mp4_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_mp4\` ; $(OBJCLINK) $(libmux_mp4_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_mp4` ;; \
	  c|*) echo $(LINK) $(libmux_mp4_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_mp4\` ; $(LINK) $(libmux_mp4_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_mp4` ;; \
	esac


# The mux_asf plugin

if UNTRUE
Lmux_asfp = libmux_asf_plugin.a
Dmux_asfp = libmux_asf_plugin$(LIBEXT)
Lmux_asfb = libmux_asf.a
Lmux_asfpic = libmux_asf_pic.a
endif

libmux_asf_plugin_a_SOURCES = $(SOURCES_mux_asf)
libmux_asf_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin mux_asf`
libmux_asf_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin mux_asf`
libmux_asf_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin mux_asf`

libmux_asf_pic_a_SOURCES = $(SOURCES_mux_asf)
libmux_asf_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic mux_asf`
libmux_asf_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic mux_asf`
libmux_asf_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic mux_asf`

libmux_asf_a_SOURCES = $(SOURCES_mux_asf)
libmux_asf_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin mux_asf`
libmux_asf_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin mux_asf`
libmux_asf_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin mux_asf`

libvlc_LIBRARIES += $(Lmux_asfb) $(Lmux_asfpic)
libmux_asf_DATA = $(Dmux_asfp)

libmux_asfdir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lmux_asfp)
libmux_asf_plugin$(LIBEXT): $(libmux_asf_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage mux_asf` in \
	  c++) echo $(CXXLINK) $(libmux_asf_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_asf\` ; $(CXXLINK) $(libmux_asf_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_asf` ;; \
	  objc) echo $(OBJCLINK) $(libmux_asf_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_asf\` ; $(OBJCLINK) $(libmux_asf_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_asf` ;; \
	  c|*) echo $(LINK) $(libmux_asf_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_asf\` ; $(LINK) $(libmux_asf_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_asf` ;; \
	esac


# The mux_wav plugin

if UNTRUE
Lmux_wavp = libmux_wav_plugin.a
Dmux_wavp = libmux_wav_plugin$(LIBEXT)
Lmux_wavb = libmux_wav.a
Lmux_wavpic = libmux_wav_pic.a
endif

libmux_wav_plugin_a_SOURCES = $(SOURCES_mux_wav)
libmux_wav_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin mux_wav`
libmux_wav_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin mux_wav`
libmux_wav_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin mux_wav`

libmux_wav_pic_a_SOURCES = $(SOURCES_mux_wav)
libmux_wav_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic mux_wav`
libmux_wav_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic mux_wav`
libmux_wav_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic mux_wav`

libmux_wav_a_SOURCES = $(SOURCES_mux_wav)
libmux_wav_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin mux_wav`
libmux_wav_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin mux_wav`
libmux_wav_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin mux_wav`

libvlc_LIBRARIES += $(Lmux_wavb) $(Lmux_wavpic)
libmux_wav_DATA = $(Dmux_wavp)

libmux_wavdir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lmux_wavp)
libmux_wav_plugin$(LIBEXT): $(libmux_wav_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage mux_wav` in \
	  c++) echo $(CXXLINK) $(libmux_wav_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_wav\` ; $(CXXLINK) $(libmux_wav_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_wav` ;; \
	  objc) echo $(OBJCLINK) $(libmux_wav_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_wav\` ; $(OBJCLINK) $(libmux_wav_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_wav` ;; \
	  c|*) echo $(LINK) $(libmux_wav_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_wav\` ; $(LINK) $(libmux_wav_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_wav` ;; \
	esac


# The mux_mpjpeg plugin

if UNTRUE
Lmux_mpjpegp = libmux_mpjpeg_plugin.a
Dmux_mpjpegp = libmux_mpjpeg_plugin$(LIBEXT)
Lmux_mpjpegb = libmux_mpjpeg.a
Lmux_mpjpegpic = libmux_mpjpeg_pic.a
endif

libmux_mpjpeg_plugin_a_SOURCES = $(SOURCES_mux_mpjpeg)
libmux_mpjpeg_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin mux_mpjpeg`
libmux_mpjpeg_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin mux_mpjpeg`
libmux_mpjpeg_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin mux_mpjpeg`

libmux_mpjpeg_pic_a_SOURCES = $(SOURCES_mux_mpjpeg)
libmux_mpjpeg_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic mux_mpjpeg`
libmux_mpjpeg_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic mux_mpjpeg`
libmux_mpjpeg_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic mux_mpjpeg`

libmux_mpjpeg_a_SOURCES = $(SOURCES_mux_mpjpeg)
libmux_mpjpeg_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin mux_mpjpeg`
libmux_mpjpeg_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin mux_mpjpeg`
libmux_mpjpeg_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin mux_mpjpeg`

libvlc_LIBRARIES += $(Lmux_mpjpegb) $(Lmux_mpjpegpic)
libmux_mpjpeg_DATA = $(Dmux_mpjpegp)

libmux_mpjpegdir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lmux_mpjpegp)
libmux_mpjpeg_plugin$(LIBEXT): $(libmux_mpjpeg_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage mux_mpjpeg` in \
	  c++) echo $(CXXLINK) $(libmux_mpjpeg_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_mpjpeg\` ; $(CXXLINK) $(libmux_mpjpeg_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_mpjpeg` ;; \
	  objc) echo $(OBJCLINK) $(libmux_mpjpeg_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_mpjpeg\` ; $(OBJCLINK) $(libmux_mpjpeg_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_mpjpeg` ;; \
	  c|*) echo $(LINK) $(libmux_mpjpeg_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mux_mpjpeg\` ; $(LINK) $(libmux_mpjpeg_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mux_mpjpeg` ;; \
	esac


