

#include "File.h"
/** ' Store the information for the new File.  If the file size
    ' Is zero, indicate with a -2 in the Fat Entry, otherwise call the 
    ' FatClusters New File routine.  If -1 is returned, then no room
    ' For the file, which will be handled by the Directory Class
		 *
		 * @param string fileName, bool readOnly, int nSize
		 * @return null
		 * @precondition  Windows operating system.
		 */
File:: File()
{
	date=getDate();
}

File:: File(string fileName, bool readOnly, int nSize)
{
	msName=fileName;
	mbReadOnly=readOnly;
	mnSize=nSize;
	date=getDate();
	if (mnSize>0)
		mnFatEntry=newFile(mnSize);
	else
		mnFatEntry=-2;


	
	working="\n File working\n";
	cout << working;
}
/** '    Used for Read from file dump.  The FAT was reloaded separately.	
    '	 Update the class attributes and move on!!
		 *
		 * @param string fileName, bool readOnly, int nSize, int cluster
		 * @return null
		 * @precondition  Windows operating system.
		 */
File:: File(string fileName, bool readOnly, int nSize, int cluster)
{
	msName=fileName;
	mbReadOnly=readOnly;
	mnSize=nSize;
	date=getDate();
	mnFatEntry=cluster;

}

string File::getFileName()
{
	return msName;
}



bool File::getReadOnly()
{ 
	return mbReadOnly;
}


string File::getDate()
{
	return "working";
}


int File::getFileSize()
{
	return mnSize;
}


int File::getStartCluster()
{
	return mnFatEntry;

}
/** 'Delete File ()
    'Remove all clusters from the File
    'If First Cluster Pointer is not -2 
    'Call Cluster.DeleteFile(First Cluster Pointer)
		 *
		 * @param void
		 * @return void
		 * @precondition  Windows operating system.
		 */
void File:: fDeleteFile()
{
	if (mnFatEntry!=-2)
	{
		deleteFile(mnFatEntry);	// calling the parent function;
	}
	mnFatEntry=-2;	// empty ?! 
}


/** 'Change File (New File Size, Read Only Switch) Returns Boolean
    ' Changes Read Only Switch of File and Potentially File Size
    ' Set ReadOnlySwitch to value passed in
    ' Compare New File Size with File Size
    ' If no change in clusters
    '	Return True
    ' If new size is zero
    '    call Cluster.Delete File
    '    set First Cluser Pointer to -2
    '    Return True
    ' If Bigger then
    '	How Many Clusters do we need?
    '	Repeat for that many clusters
    '		Set Check to Cluster.AddCluster(Starting Cluster)
    '	Return Check
    ' If Smaller then
    '		How Many Fewer Clusters?
    '		Repeat for that many clusters
    '		Call Cluster.DeleteCluster(Starting Cluster)
    '		Return True
		 *
		 * @param int nSize,bool readOnly
		 * @return bool
		 * @precondition  All classes are linked and FATCluster has been successfuly constructed.
		 */

bool File:: changeFile(int nSize,bool readOnly)
{
	mbReadOnly=readOnly;
	if(nSize=0)
	{
		deleteFile(mnFatEntry);
		mnFatEntry=-2;
		mnSize=0;
		return true;
	}
	int startBytes=mnSize/getClusterSize()+1;
	int endBytes= nSize/getClusterSize()+1;
	if(startBytes==endBytes)
	{
		mnSize=nSize;
			return true;
	}
	if (endBytes>startBytes)
	{
		int needBytes=endBytes-startBytes;
		bool bContinue=true;
		for (int i=1;i<=needBytes;i++)
		{
			if (addCluster(mnFatEntry)==false)
				return false;
		}
		
		mnSize=nSize;
		return true;
	}
	else
	{
		int lessBytes=endBytes-startBytes;
		for (int i=1;i<=lessBytes;i++)
		{
			deleteCluster(mnFatEntry);
		}
		mnSize=nSize;
		return true;
	}


}