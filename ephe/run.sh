FILE_LIST=`awk -v d="," '{s=(NR==1?s:s d)$0}END{print s}' filelist.txt`;
cd ./download && curl -O "https://www.astro.com/ftp/swisseph/ephe/{$FILE_LIST}";