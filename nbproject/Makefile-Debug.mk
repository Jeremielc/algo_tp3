#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/sources/functions.o \
	${OBJECTDIR}/sources/lists.o \
	${OBJECTDIR}/sources/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algo_tp3

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algo_tp3: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algo_tp3 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/sources/functions.o: sources/functions.c 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/functions.o sources/functions.c

${OBJECTDIR}/sources/lists.o: sources/lists.c 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/lists.o sources/lists.c

${OBJECTDIR}/sources/main.o: sources/main.c 
	${MKDIR} -p ${OBJECTDIR}/sources
	${RM} "$@.d"
	$(COMPILE.c) -g -std=c99 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/sources/main.o sources/main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algo_tp3

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
