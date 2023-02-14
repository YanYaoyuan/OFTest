QT       += core gui network serialport charts opengl
# 上行删除openglextension，否则出现找不到此项报错
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 resources_big

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

QMAKE_MSC_VER = 1900
DEFINES += WIN32_LEAN_AND_MEAN

SOURCES += \
    adc.cpp \
    datatable.cpp \
    document.cpp \
    fpga.cpp \
    ip_config.cpp \
    FileIO.cpp \
    Tools.cpp \
    laser.cpp \
    MyCloud.cpp \
    main.cpp \
    mainwindow.cpp \
    mems.cpp \
    #opengl_show.cpp \
    pcap_analysis.cpp \
    #pointcloud.cpp \
    printview.cpp \
    receiver.cpp \
    registe_configure.cpp \
    serial_port.cpp \
    #qscarletopenglinterface.cpp\
    #qscarlet_pointio.cpp \
    #qscarlet_selectionstudyfrm.cpp \
    #spreadsheet/spreadsheet.cpp \
    #spreadsheet/spreadsheetdelegate.cpp \
 \    #spreadsheet/spreadsheetitem.cpp
 \    #temperature.cpp
    temperature_realshow.cpp \
    voltage_realshow.cpp

HEADERS += \
    adc.h \
    datatable.h \
    document.h \
    fpga.h \
    ip_config.h \
    FileIO.h \
    Tools.h \
    laser.h \
    Mycloud.h \
    mainwindow.h \
    mems.h \
    #opengl_show.h \
    pcap_analysis.h \
    #pointcloud.h \
    printview.h \
    receiver.h \
    registe_configure.h \
    serial_port.h \
    #temperature.h
    #qscarletopenglinterface.h \
    #qscarlet_pointio.h \
    #qscarlet_selectionstudyfrm.h \
    #spreadsheet/spreadsheet.h \
    #spreadsheet/spreadsheetdelegate.h \
 \     #spreadsheet/spreadsheetitem.h
    temperature_realshow.h \
    voltage_realshow.h

FORMS += \
    adc.ui \
    datatable.ui \
    document.ui \
    fpga.ui \
    ip_config.ui \
    laser.ui \
    mainwindow.ui \
    mems.ui \
    receiver.ui \
    registe_configure.ui \
    #qscarlet_selectionstudyfrm.ui \
    serial_port.ui \
 \    #temperature.ui
    temperature_realshow.ui \
    voltage_realshow.ui


INCLUDEPATH += D:/Software/PCL/PCL1.12.1/include/pcl-1.12

INCLUDEPATH += D:/Software/PCL/PCL1.12.1/3rdParty/Boost/include/boost-1_78

INCLUDEPATH += D:/Software/PCL/PCL1.12.1/3rdParty/Eigen/eigen3

INCLUDEPATH += D:/Software/PCL/PCL1.12.1/3rdParty/FLANN/include

INCLUDEPATH += D:/Software/PCL/PCL1.12.1/3rdParty/Qhull/include

#INCLUDEPATH += C:/DEV/vtk_install/vtk_8.1/include/vtk-8.0

INCLUDEPATH += D:/Software/PCL/PCL1.12.1/3rdParty/OpenNI2/Include

INCLUDEPATH += C:/DEV/WpdPack/Include

INCLUDEPATH += C:/DEV/VTK910/include/vtk-9.1

INCLUDEPATH += D:/Software/PCL/PCL1.12.1/3rdParty/Eigen/eigen3





CONFIG(debug,debug|release){

LIBS += -LD:/Software/PCL/PCL1.12.1/lib\
        -lpcl_commond\
        -lpcl_featuresd\
        -lpcl_filtersd\
        -lpcl_iod\
        -lpcl_io_plyd\
        -lpcl_kdtreed\
        -lpcl_keypointsd\
        -lpcl_mld\
        -lpcl_octreed\
        -lpcl_outofcored\
        -lpcl_peopled\
        -lpcl_recognitiond\
        -lpcl_registrationd\
        -lpcl_sample_consensusd\
        -lpcl_searchd\
        -lpcl_segmentationd\
        -lpcl_stereod\
        -lpcl_surfaced\
        -lpcl_trackingd\
        -lpcl_visualizationd

LIBS += -LD:/Software/PCL/PCL1.12.1/3rdParty/FLANN\lib\
        -lflann-gd\
        -lflann_cpp-gd\
        -lflann_cpp_s-gd\
        -lflann_s-gd


LIBS += -LD:/Software/PCL/PCL1.12.1/3rdParty/Qhull/lib\
        -lqhullcpp_d\
        -lqhullstatic_d\
        -lqhullstatic_rd\
        -lqhull_rd



LIBS += -LE:/PCL1121/3rdParty/Boost/lib\
        -llibboost_atomic-vc142-mt-gd-x64-1_78\
        -llibboost_bzip2-vc142-mt-gd-x64-1_78\
        -llibboost_chrono-vc142-mt-gd-x64-1_78\
        -llibboost_container-vc142-mt-gd-x64-1_78\
        -llibboost_context-vc142-mt-gd-x64-1_78\
        -llibboost_contract-vc142-mt-gd-x64-1_78\
        -llibboost_coroutine-vc142-mt-gd-x64-1_78\
        -llibboost_date_time-vc142-mt-gd-x64-1_78\
        -llibboost_exception-vc142-mt-gd-x64-1_78\
        -llibboost_filesystem-vc142-mt-gd-x64-1_78\
        -llibboost_graph-vc142-mt-gd-x64-1_78\
        -llibboost_graph_parallel-vc142-mt-gd-x64-1_78\
        -llibboost_iostreams-vc142-mt-gd-x64-1_78\
        -llibboost_json-vc142-mt-gd-x64-1_78\
        -llibboost_locale-vc142-mt-gd-x64-1_78\
        -llibboost_log-vc142-mt-gd-x64-1_78\
        -llibboost_log_setup-vc142-mt-gd-x64-1_78\
        -llibboost_math_c99-vc142-mt-gd-x64-1_78\
        -llibboost_math_c99f-vc142-mt-gd-x64-1_78\
        -llibboost_math_c99l-vc142-mt-gd-x64-1_78\
        -llibboost_math_tr1-vc142-mt-gd-x64-1_78\
        -llibboost_math_tr1f-vc142-mt-gd-x64-1_78\
        -llibboost_math_tr1l-vc142-mt-gd-x64-1_78\
        -llibboost_mpi-vc142-mt-gd-x64-1_78\
        -llibboost_nowide-vc142-mt-gd-x64-1_78\
        -llibboost_numpy38-vc142-mt-gd-x64-1_78\
        -llibboost_prg_exec_monitor-vc142-mt-gd-x64-1_78\
        -llibboost_program_options-vc142-mt-gd-x64-1_78\
        -llibboost_python38-vc142-mt-gd-x64-1_78\
        -llibboost_random-vc142-mt-gd-x64-1_78\
        -llibboost_regex-vc142-mt-gd-x64-1_78\
        -llibboost_serialization-vc142-mt-gd-x64-1_78\
        -llibboost_system-vc142-mt-gd-x64-1_78\
        -llibboost_test_exec_monitor-vc142-mt-gd-x64-1_78\
        -llibboost_thread-vc142-mt-gd-x64-1_78\
        -llibboost_timer-vc142-mt-gd-x64-1_78\
        -llibboost_type_erasure-vc142-mt-gd-x64-1_78\
        -llibboost_unit_test_framework-vc142-mt-gd-x64-1_78\
        -llibboost_wave-vc142-mt-gd-x64-1_78\
        -llibboost_wserialization-vc142-mt-gd-x64-1_78\
        -llibboost_zlib-vc142-mt-gd-x64-1_78


LIBS += -LE:/PCL1121/3rdParty/OpenNI2/lib\
        -lOpenNI2


LIBS += -LE:/WpdPack/Lib/x64\
        -lwpcap\
        -lPacket



} else {

LIBS += -LC:/DEV/WpdPack/Lib/x64\
        -lwpcap\
        -lPacket




LIBS += -LD:/Software/PCL/PCL1.12.1/lib\
        -lpcl_common\
        -lpcl_features\
        -lpcl_filters\
        -lpcl_io\
        -lpcl_io_ply\
        -lpcl_kdtree\
        -lpcl_keypoints\
        -lpcl_ml\
        -lpcl_octree\
        -lpcl_outofcore\
        -lpcl_people\
        -lpcl_recognition\
        -lpcl_registration\
        -lpcl_sample_consensus\
        -lpcl_search\
        -lpcl_segmentation\
        -lpcl_stereo\
        -lpcl_surface\
        -lpcl_tracking\
        -lpcl_visualization


LIBS += -LD:/Software/PCL/PCL1.12.1/3rdParty/FLANN/lib\
        -lflann\
        -lflann_cpp\
        -lflann_cpp_s\
        -lflann_s


LIBS += -LD:/Software\PCL/PCL1.12.1/3rdParty/Boost/lib\
        -llibboost_atomic-vc142-mt-x64-1_78\
        -llibboost_bzip2-vc142-mt-x64-1_78\
        -llibboost_chrono-vc142-mt-x64-1_78\
        -llibboost_container-vc142-mt-x64-1_78\
        -llibboost_context-vc142-mt-x64-1_78\
        -llibboost_contract-vc142-mt-x64-1_78\
        -llibboost_coroutine-vc142-mt-x64-1_78\
        -llibboost_date_time-vc142-mt-x64-1_78\
        -llibboost_exception-vc142-mt-x64-1_78\
        -llibboost_filesystem-vc142-mt-x64-1_78\
        -llibboost_graph-vc142-mt-x64-1_78\
        -llibboost_graph_parallel-vc142-mt-x64-1_78\
        -llibboost_iostreams-vc142-mt-x64-1_78\
        -llibboost_json-vc142-mt-x64-1_78\
        -llibboost_locale-vc142-mt-x64-1_78\
        -llibboost_log-vc142-mt-x64-1_78\
        -llibboost_log_setup-vc142-mt-x64-1_78\
        -llibboost_math_c99-vc142-mt-x64-1_78\
        -llibboost_math_c99f-vc142-mt-x64-1_78\
        -llibboost_math_c99l-vc142-mt-x64-1_78\
        -llibboost_math_tr1-vc142-mt-x64-1_78\
        -llibboost_math_tr1f-vc142-mt-x64-1_78\
        -llibboost_math_tr1l-vc142-mt-x64-1_78\
        -llibboost_mpi-vc142-mt-x64-1_78\
        -llibboost_nowide-vc142-mt-x64-1_78\
        -llibboost_numpy38-vc142-mt-x64-1_78\
        -llibboost_prg_exec_monitor-vc142-mt-x64-1_78\
        -llibboost_program_options-vc142-mt-x64-1_78\
        -llibboost_python38-vc142-mt-x64-1_78\
        -llibboost_random-vc142-mt-x64-1_78\
        -llibboost_regex-vc142-mt-x64-1_78\
        -llibboost_serialization-vc142-mt-x64-1_78\
        -llibboost_system-vc142-mt-x64-1_78\
        -llibboost_test_exec_monitor-vc142-mt-x64-1_78\
        -llibboost_thread-vc142-mt-x64-1_78\
        -llibboost_timer-vc142-mt-x64-1_78\
        -llibboost_type_erasure-vc142-mt-x64-1_78\
        -llibboost_unit_test_framework-vc142-mt-x64-1_78\
        -llibboost_wave-vc142-mt-x64-1_78\
        -llibboost_wserialization-vc142-mt-x64-1_78\
        -llibboost_zlib-vc142-mt-x64-1_78


LIBS += -LD:/Software/PCL/PCL1.12.1/3rdParty/Qhull/lib\
        -lqhullcpp\
        -lqhullstatic\
        -lqhullstatic_r\
        -lqhull_r

#LIBS += -LC:/Program Files/OpenNI2/Lib\
#        -lOpenNI2

win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkcgns-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkChartsCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkCommonColor-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkCommonComputationalGeometry-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkCommonCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkCommonDataModel-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkCommonExecutionModel-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkCommonMath-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkCommonMisc-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkCommonSystem-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkCommonTransforms-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkDICOMParser-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkDomainsChemistry-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkDomainsChemistryOpenGL2-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkdoubleconversion-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkexodusII-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkexpat-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersAMR-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersExtraction-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersFlowPaths-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersGeneral-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersGeneric-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersGeometry-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersHybrid-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersHyperTree-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersImaging-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersModeling-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersParallel-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersParallelImaging-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersPoints-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersProgrammable-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersSelection-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersSMP-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersSources-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersStatistics-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersTexture-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersTopology-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkFiltersVerdict-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkfmt-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkfreetype-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkGeovisCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkgl2ps-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkglew-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkGUISupportQt-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkGUISupportQtQuick-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkGUISupportQtSQL-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkhdf5-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkhdf5_hl-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingColor-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingFourier-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingGeneral-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingHybrid-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingMath-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingMorphological-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingSources-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingStatistics-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkImagingStencil-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkInfovisCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkInfovisLayout-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkInteractionImage-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkInteractionStyle-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkInteractionWidgets-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOAMR-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOAsynchronous-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOCGNSReader-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOChemistry-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOCityGML-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOCONVERGECFD-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOEnSight-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOExodus-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOExport-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOExportGL2PS-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOExportPDF-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOGeometry-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOHDF-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOImage-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOImport-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOInfovis-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOIOSS-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOLegacy-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOLSDyna-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOMINC-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOMotionFX-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOMovie-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIONetCDF-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOOggTheora-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOParallel-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOParallelXML-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOPLY-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOSegY-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOSQL-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkioss-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOTecplotTable-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOVeraOut-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOVideo-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOXML-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkIOXMLParser-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkjpeg-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkjsoncpp-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkkissfft-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtklibharu-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtklibproj-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtklibxml2-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkloguru-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtklz4-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtklzma-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkmetaio-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtknetcdf-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkogg-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkParallelCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkParallelDIY-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkpng-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkpugixml-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingAnnotation-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingContext2D-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingContextOpenGL2-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingFreeType-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingGL2PSOpenGL2-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingImage-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingLabel-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingLOD-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingOpenGL2-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingQt-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingSceneGraph-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingUI-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingVolume-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingVolumeOpenGL2-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkRenderingVtkJS-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtksqlite-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtksys-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkTestingRendering-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtktheora-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtktiff-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkverdict-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkViewsContext2D-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkViewsCore-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkViewsInfovis-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkViewsQt-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkWrappingTools-9.1.lib)
win32:LIBS += $$quote(C:\DEV\VTK910\lib\vtkzlib-9.1.lib)
win32:LIBS += -L$$quote(C:\DEV\VTK910\bin)

}
TRANSLATIONS += \
    #OF_lidar_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

RESOURCES += \
    mainwindow.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    1.jpg

