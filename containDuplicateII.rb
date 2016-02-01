# @param {Integer[]} nums
# @param {Integer} k
# @return {Boolean}
def contains_nearby_duplicate(nums, k)
    if nums.size() == 0 
        return false
    end
    if nums.uniq.length == nums.length 
        return false
    end 
    for  i in  0..nums.size()
        for j in 1..k
            if i+j>= nums.size()
                break
            end
            if  (nums[i] == nums[i+j])  then
                return true
            end
        end
    end
    false
end

p contains_nearby_duplicate([-1,-1],1)
