module type Message = {
  type t;
  let from_proto: Protobuf.Reader.t => Protobuf.Result.t(t);
  let to_proto: t => Protobuf.Writer.t;
};

type endpoint('req, 'res) = (
  module Message with type t = 'req,
  module Message with type t = 'res,
);
