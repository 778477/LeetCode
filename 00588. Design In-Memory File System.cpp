//
//  main.cpp
//  leetCode
//
//  Created by miaoyou.gmy
//  Copyright © 2016年 miaoyou.gmy. All rights reserved.
//


#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


/**
 
 588. Design In-Memory File System
 
 Design an in-memory file system to simulate the following functions:
 
 ls: Given a path in string format. If it is a file path, return a list that only contains this file's name. If it is a directory path, return the list of file and directory names in this directory. Your output (file and directory names together) should in lexicographic order.
 
 mkdir: Given a directory path that does not exist, you should make a new directory according to the path. If the middle directories in the path don't exist either, you should create them as well. This function has void return type.
 
 addContentToFile: Given a file path and file content in string format. If the file doesn't exist, you need to create that file containing given content. If the file already exists, you need to append given content to original content. This function has void return type.
 
 readContentFromFile: Given a file path, return its content in string format.
 
 Example:
 Input:
 ["FileSystem","ls","mkdir","addContentToFile","ls","readContentFromFile"]
 [[],["/"],["/a/b/c"],["/a/b/c/d","hello"],["/"],["/a/b/c/d"]]
 Output:
 [null,[],null,null,["a"],"hello"]
 Explanation:
 filesystem
 Note:
 You can assume all file or directory paths are absolute paths which begin with / and do not end with / except that the path is just "/".
 You can assume that all operations will be passed valid parameters and users will not attempt to retrieve file content or list a directory or file that does not exist.
 You can assume that all directory names and file names only contain lower-case letters, and same names won't exist in the same directory.
 
 
 */

/*
 
 63 / 63 test cases passed.
 Status: Accepted
 Runtime: 12 ms
 
 */

enum fileType{
    FileType,
    DirectoryType
};

class baseFileNode{
public:
    string name;
    fileType type;
};

class File : public baseFileNode{
public:
    string content;
};

class Directory : public baseFileNode{
public:
    map<string,baseFileNode *> files;
};

class FileSystem {
public:
    const char seg = '/';
    FileSystem() {
        root = new Directory();
    }
    
    void Destroy(Directory *root){}
    
    ~FileSystem(){
        Destroy(root);
        delete root;
    }
    
    vector<string> ls(string path) {
        Directory *current = root;
        vector<string> res;
        string name = "";
        
        for (char ch : path){
            if((ch == seg && name.length() > 0)){
                current = (Directory *)current->files[name];
                name.clear();
            } else if(ch != seg){
                name += ch;
            }
        }
        
        if(name.length() > 0){
            if(current->files[name]->type == FileType){
                res.push_back(name);
                return res;
            } else {
                current = (Directory *)current->files[name];
            }
        }
        
        for(pair<string, baseFileNode *> file : current->files){
            res.push_back(file.second->name);
        }
        sort(res.begin(),res.end());
        return res;
    }
    
    void mkdir(string path) {
        Directory *current = root;
        string name = "";
        for (char ch : path){
            if((ch == seg && name.length() > 0)){
                if(!current->files[name]){
                    Directory *tmp = new Directory();
                    tmp->name = name,tmp->type = DirectoryType;
                    current->files[name] = tmp;
                    current = tmp;
                } else {
                    current = (Directory *)current->files[name];
                }
                name.clear();
            } else if(ch != seg){
                name += ch;
            }
        }
        
        if(name.length() > 0 && !current->files[name]){
            Directory *tmp = new Directory();
            tmp->name = name,tmp->type = DirectoryType;
            current->files[name] = tmp;
        }
    }
    
    void addContentToFile(string filePath, string content) {
        Directory *current = root;
        string name = "";
        
        for (char ch : filePath){
            if(ch == seg && name.length() > 0){
                if(!current->files[name]){
                    Directory *tmp = new Directory();
                    tmp->name = name,tmp->type = DirectoryType;
                    current->files[name] = tmp;
                    current = tmp;
                } else {
                    current = (Directory *)current->files[name];
                }
                name.clear();
            } else if(ch != seg){
                name += ch;
            }
        }
        
        if(!current->files[name]){
            File *file = new File();
            file->name = name,file->type = FileType;
            file->content = "";
            current->files[name] = file;
        }
        
        ((File *)current->files[name])->content += content;
    }
    
    string readContentFromFile(string filePath) {
        Directory *current = root;
        string name = "";
        for (char ch : filePath){
            if(ch == seg && name.length() > 0){
                current = (Directory *)current->files[name];
                name.clear();
            } else if(ch != seg){
                name += ch;
            }
        }
        return ((File *)current->files[name])->content;
    }
private:
    Directory *root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */


void output(vector <string> res){
    cout<<"[";
    for (string r : res){
        cout<<r<<",";
    }
    cout<<"]"<<endl;
}

int main(){
    FileSystem fileSystem;
    
    
    output(fileSystem.ls("/"));
    fileSystem.mkdir("/a/b/c");
    output(fileSystem.ls("/"));
    fileSystem.addContentToFile("/a/b/c/d", "Hello");
    cout<<fileSystem.readContentFromFile("/a/b/c/d")<<endl;
    
    
    //    output(fileSystem.ls("/"));
    //    fileSystem.mkdir("/a/b/c");
    //    output(fileSystem.ls("/a/b"));
    //
    
    return 0;
}
