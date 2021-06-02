struct HashTable{
    int key, val;
    UT_hash_handle hh;
};//哈希表结构

bool checkSubarraySum(int* nums, int numsSize, int k){
    int m = numsSize;//m为数组大小
    if(m < 2){
        return false;//若初始数组大小小于2则直接false
    }
    struct HashTable* hashTable = NULL;//定义哈希表指针指向空
    struct HashTable* tmp = malloc(sizeof(struct HashTable));//创建哈希表，并把指针指向tmp
    tmp->key = 0, tmp->val = -1;//表的初始位置设置值为-1，当前两个数和刚好整除k时，能够判定true
    HASH_ADD_INT(hashTable, key, tmp);//定义往表添加数据函数
    int remainder = 0;//定义余数
    for(int i = 0; i < m ; i++){
        remainder = (remainder + nums[i]) % k;
        HASH_FIND_INT(hashTable, &remainder, tmp);
        if(tmp != NULL){
            int prevIndex = tmp->val;
            if(i - prevIndex >= 2){
                return true;
            }
        } else{
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = remainder, tmp->val =i;
            HASH_ADD_INT(hashTable, key, tmp);
        }
    }
    return false;
}