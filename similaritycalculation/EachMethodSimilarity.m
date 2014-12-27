function EachMethodData=EachMethodSimilarity(MethodsNum,ImageQuantity)
%~~~~~图像存放的路径~~~~~
[strGroundTruth,idsGroundTruth]=ImagePathGroundTruth();
[strMethod,idsMethod]=ImagePathMethods(MethodsNum);
%~~~~~计算每种方法的相似度~~~~~
EachMethodData=zeros(ImageQuantity,1);
for ImageNum=1:ImageQuantity 
    EachMethodData(ImageNum,1)=EachImageSimilarity( strGroundTruth,idsGroundTruth,strMethod,idsMethod,ImageNum );
end
