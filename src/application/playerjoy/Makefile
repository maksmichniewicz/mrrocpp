#----------- ecp_mp/irp6_on_track catalog makefile of the MRROC++ frame system --------------#
#======================================================#

SOURCES = ${wildcard *.cc}
OBJECTS = ${patsubst %.cc,%.o,${SOURCES}}

BINARIES =			ecp_playerjoy

ifneq ($(BUILD_TARGET), linux)
BINARIES+=			
endif


#-----------------------------------------------------------------------------------------------------------------------#
# Should be modified only by developers not by users
HOMEDIR = ../../..
include $(HOMEDIR)/common.mk
KIN_OBJECTS = ${KIN_DIR}/irp6_on_track/libkinematicsirp6ot.a ${KIN_DIR}/irp6_postument/libkinematicsirp6p.a $(KIN_DIR)/common/libkinematics.a

SHOBJ = ../../ecp/irp6_on_track/ecp_r_irp6ot.o \
	${KIN_OBJECTS} ../../ecp/common/libecp.a ../../ecp_mp/libecp_mp.a $(LIBDIR)/libmrrocpp.a
#======================================================#	
.PHONY: all clean install
#------------------------------------------------- Build rules -------------------------------------------------------#
all: ${BINARIES}

#-----------------------------------------------------------------------------------------------------------------------#
ecp_playerjoy: ecp_t_playerjoy_irp6ot.o ecp_g_pjg.o ecp_mp_tr_player.o $(LIBDIR)/libplayerc.a $(SHOBJ)
	$(LD) $(LDFLAGS) -o $@ $^
	
	

#---------------------------------Special object build rules (user made)-------------------------------------#
# e.g:
# plik.o: plik.cc plik1.h plik2.h ... itd
#	$(CXX) -c user_flags -I$(HOMEDIR)/include -o $@ $<
#======================================================#	
#----------------------------------------------- Maintain rules ----------------------------------------------------#
install: ${BINARIES}
	${INSTALL} ${BINARIES} $(BINDIR)
#-----------------------------------------------------------------------------------------------------------------------#
clean:
	@rm -f *.o *.err ${BINARIES} ./.deps/*.P ./sensor/*.o ./sensor/*.err ./generator/*.o ./generator/*.err
#-----------------------------------------------------------------------------------------------------------------------#

include $(HOMEDIR)/depend.mk
