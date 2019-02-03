#include "basicclass.h"

BasicClass::BasicClass()
{}

//File related 文件相关 start-------------

///
/// \brief 打印文件列表
/// \param file_path
///
void BasicClass::DisplayFileList(const string &file_path){
    DIR    *dir;
    struct    dirent    *ptr;
    dir = opendir(file_path.c_str()); ///open the dir

    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        cout<<ptr->d_name<<endl;
    }
    closedir(dir);
}

///
/// \brief BasicClass::FileExist 文件是否存在
/// \param file_path
/// \param file_name 文件名+类型
/// \return 文件名是否在路径下存在
///
bool BasicClass::FileExist(const string &file_path, const string &file_name){
    DIR *dir;
    struct dirent *ptr;
    dir = opendir(file_path.c_str()); ///open the dir
    while((ptr = readdir(dir)) != NULL) ///read the list of this dir
    {
        string str_name(ptr->d_name);
        if(str_name==file_name){
            closedir(dir);
            return true;
        }
    }
    closedir(dir);
    cout<<"Error (bc-001): Can not find "<<file_name<<" in "<<file_path<<endl;
    return false;
}
//File related 文件相关 end-------------

vector<GPoint> BasicClass::ReadPointData(const string &file_path, const string &file_name)
{
    vector<GPoint> traj_points;
    if(!FileExist(file_path,file_name)){
        return traj_points;
    }
    //input file
    FILE* file_in=fopen((file_path+file_name).c_str (),"r");

    while(true) {
        GPoint point_new;
        int result=fscanf(file_in, "%lf %lf %lf",&point_new.lon, &point_new.lat, &point_new.dir);
        if(result<=0){
            break;
        }
        traj_points.push_back(point_new);
    }
    fclose(file_in);
    //cout<<"num points: "<<traj_points.size()<<endl;
    return traj_points;
}

//Error template
//cout<<"Error (bc-000): <<endl;
