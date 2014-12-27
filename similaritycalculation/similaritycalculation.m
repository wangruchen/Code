
strGroundTruth = './groundtruth/';      
SuffixGroundTruth = '*.png'; 
PathGroundTruth = strcat(strGroundTruth,SuffixGroundTruth);
idsGroundTruth = dir(PathGroundTruth);
ImageQuantity=length(idsGroundTruth);%图像的张数;

strMethod = './method/';      
idsMethod = dir(strMethod);
MethodsQuantity=length(idsMethod)-1;%方法数量+1

%~~~~~~在.txt中写入表头~~~~~
fid=fopen( 'data.txt' , 'w' );
	fprintf(fid,'%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s \n','','1Canny','2ITS','3Otsu','4MET','5Kmeans','6Salient','7Remove','8Watershed');
fclose(fid);
%~~~~~~~计算出的相似度数据~~~~~~~~~~~~~~~~~~
SimilarityData=zeros(ImageQuantity,MethodsQuantity);
for MethodsNum=1:MethodsQuantity
    if MethodsNum==1%~~~数组的第一列为图像的编号
       for ImageNum=1:ImageQuantity
           SimilarityData(ImageNum,MethodsNum)=ImageNum;
       end
    else
        EachMethodData=EachMethodSimilarity(MethodsNum,ImageQuantity);%计算每种方法的相似度
        for ImageNum=1:ImageQuantity
            SimilarityData(ImageNum,MethodsNum)=EachMethodData(ImageNum,1); %将所有方法的相似度存放在同一个数组中
        end
    end
end

%~~~~~~~将数据存放在.txt中~~~~~~~
for ImageNum=1:ImageQuantity
    for MethodsNum=1:MethodsQuantity
        fid=fopen( 'data.txt' , 'a+' );
        fprintf(fid,'%f\t ',SimilarityData(ImageNum,MethodsNum));
        fclose(fid);
    end
    fid=fopen( 'data.txt' , 'a+' );
    fprintf(fid,'\n');
    fclose(fid);
end