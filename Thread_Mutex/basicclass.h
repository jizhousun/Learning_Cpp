#ifndef BASICCLASS_H
#define BASICCLASS_H

#include <iostream>
#include<math.h>
#include<vector>
#include<queue>
#include <unistd.h>
#include "dirent.h"

using namespace std;

class Point
{
public:
    double x; //horizontal direction from left to right on screen
    double y;//vertical  direction from bottom to top on screen

    Point(){}
    Point(double x, double y):x(x),y(y){ }
};

class GPoint
{
public :
    double lon;      //经度
    double lat;      //纬度
    double dir;      //航向
    GPoint(){}
    GPoint(double lon, double lat, double dir):lon(lon),lat(lat),dir(dir){}
};

class BasicClass
{
public:
    BasicClass();

    //File related 文件相关 start-------------

    ///
    /// \brief 打印文件列表
    /// \param file_path
    ///
    void DisplayFileList(const string &file_path);

    ///
    /// \brief BasicClass::FileExist 文件是否存在
    /// \param file_path
    /// \param file_name 文件名+类型
    /// \return 文件名是否在路径下存在
    ///
    bool FileExist(const string &file_path, const string &file_name);
    //File related 文件相关 end-------------


    ///
    /// \brief Get GPoints from file system
    /// \param file_name
    /// \return vector of GNSS points
    ///
    vector<GPoint> ReadPointData(const string &file_path, const string &file_name);
};

#endif // BASICCLASS_H
