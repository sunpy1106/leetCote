def unique_paths(m,n)
	a = Array.new(m){Array.new(n)}
	(0..m-1).each{|i| a[i][n-1]=1}
	(0..n-1).each{|j| a[m-1][j]=1}
	(1..m-1).each do |i|
		(1..n-1).each do |j| 
			a[m-i-1][n-j-1] = a[m-i][n-j-1] + a[m-i-1][n-j]
		end
	end
	a[0][0]
end

p unique_paths(5,5)

