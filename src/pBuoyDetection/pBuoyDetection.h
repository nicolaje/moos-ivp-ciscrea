/**
 * \file pBuoyDetection.h
 * \brief Classe pBuoyDetection
 * \author Team CISSAU - Veni Vidi Vici (ENSTA Bretagne)
 * \version 0.1
 * \date Jun 5th 2013
 */

#ifndef pBuoyDetection_HEADER
#define pBuoyDetection_HEADER

#include <iterator>
#include "MBUtils.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "MOOS/libMOOS/App/MOOSApp.h"
#include <time.h>
#include <sys/stat.h>

using namespace std;
using namespace cv;

class pBuoyDetection : public CMOOSApp
{
    public:
        pBuoyDetection();
        ~pBuoyDetection();

    protected:
        bool OnNewMail(MOOSMSG_LIST &NewMail);
        bool Iterate();
        bool OnConnectToServer();
        bool OnStartUp();
        void RegisterVariables();

    private: // Configuration variables
        void detect(Mat img);

    private: // State variables
        unsigned int    m_iterations;
        double            m_timewarp;
        Mat img;
        bool show_process;
        string image_name, message_name, image_name_pattern, folder_name_pattern, path_save;
};

#endif 
