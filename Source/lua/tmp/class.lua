_class = {}
_class_type = {}

function class(class_name, super)
    local class_type = {}
    class_type.class_name = class_name
    --构造函数
    class_type.ctor = false
    --基类名称
    class_type.super = super
    if super then
        class_type.__super = _class[super]
    end

    function class_type:new(...)
        local obj = {}
        setmetatable(obj, {__index = _class[class_name]})
        do
            local create
            create = function(c, ...) 
                if c.super then
                    create(_class_type[c.super], ...)
                end
                --构造
                if c.ctor then
                    c.ctor(obj, ...)
                end
            end

            create(class_type, ...)
        end
        return obj
    end

    local vtbl = _class[class_name] or {}
    _class[class_name] = vtbl
    _class_type[class_name] = class_type

	setmetatable(class_type,{
        __newindex=function(t,k,v) vtbl[k]=v end,
        __index=function(t,k) return vtbl[k] end,
    })

	if super then
		setmetatable(vtbl,{__index=
            function(t,k)
				return _class[super][k]
			end
		})
	end

    return class_type
end