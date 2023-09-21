# @param {Integer[][]} heights
# @return {Integer}
def minimum_effort_path(heights)
  (0...10**6).bsearch{ |mid| find_paths(heights, mid) } || 0
end

def find_paths(heights, mid)
   visited = Array.new(heights.size){ Array.new(heights[0].size){ false } }
   queue = [[0, 0]]
   loop do
     return false if queue.empty?

     x, y = queue.pop
     neighbors(x, y, heights).each do |x1, y1|
       next if visited[x1][y1]
       next if (heights[x1][y1] - heights[x][y]).abs > mid
       return true if x1 == heights.size - 1 && y1 == heights[0].size - 1

       visited[x1][y1] = true
       queue.push([x1, y1])
     end
   end
end

def neighbors(x, y, heights)
    arr = []
    arr << [x + 1, y] if x < heights.size - 1
    arr << [x, y + 1] if y < heights[0].size - 1
    arr << [x - 1, y] if x > 0
    arr << [x, y - 1] if y > 0
    arr
end