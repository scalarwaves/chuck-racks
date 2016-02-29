//
//  FileContainerManagerModel.cpp
//  ChuckPluginTest4
//
//  Created by Rodrigo Sena on 4/22/15.
//
//

#include "FileContainerManagerModel.h"
FileContainerManagerModel::FileContainerManagerModel(chuck_inst* ck_)
{
    ck=ck_;
    consoleDocument.insertText(0, "Test text");
}
FileContainerManagerModel::~FileContainerManagerModel()
{

}
void FileContainerManagerModel::addFileContainer()
{
    fileContainerModels.push_back(new FileContainerModel(ck));
    fileContainerModels.back()->setProcessorReference(getProcessor());
}


void FileContainerManagerModel::removeFileContainer(FileContainerModel* whichPointer)
{
    //for (std::vector<FileContainerModel*>::iterator it = fileContainerModels.begin(); it != fileContainerModels.end(); ++it)
    for (int i=0; i<fileContainerModels.size(); i++) {
        if (fileContainerModels[i]==whichPointer) {
            fileContainerModels.erase(fileContainerModels.begin() + i);
            break;
        }
       
        //std::cout << ' ' << *it;
    }
}



void FileContainerManagerModel::addAllShreds()
{
     for (int i=0; i<fileContainerModels.size(); i++)
     {
         fileContainerModels.at(i)->addShred();
     }

}

FileContainerModel* FileContainerManagerModel::findFileContainer(int askedUniqueId)
{
    for (int i=0; i<fileContainerModels.size(); i++)
    {
        //fileContainerModels.at(i)->addShred();
        if (fileContainerModels.at(i)->uniqueFileContainerId == askedUniqueId )
        {
            return fileContainerModels.at(i);
        }
    }
    return nullptr;
    
}


void FileContainerManagerModel::setProcessorReference( AudioProcessor * processorReference_)
{
    processorReference = processorReference_;
}

AudioProcessor * FileContainerManagerModel::getProcessor()
{
    DBG("Entered getProcessor in fileContainerManager");
    if(processorReference != NULL)
    {
        return processorReference;
    }
    else
    {
        DBG("trying to access processor reference not set in filecontainer!!");
        return NULL;
    }
    
}
