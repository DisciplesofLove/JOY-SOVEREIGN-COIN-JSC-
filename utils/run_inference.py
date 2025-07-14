#!/usr/bin/env python3
"""Run ONNX model to produce proof-of-inference output."""

import argparse
import numpy as np
import onnxruntime as ort


def main():
    parser = argparse.ArgumentParser(description="Run inference for JSC blocks")
    parser.add_argument("--model", required=True, help="ONNX model file")
    parser.add_argument("--input", required=True, help="Binary block blob")
    parser.add_argument("--out", default="inference.bin", help="Output file")
    args = parser.parse_args()

    session = ort.InferenceSession(args.model)
    input_name = session.get_inputs()[0].name
    data = np.fromfile(args.input, dtype=np.uint8)
    result = session.run(None, {input_name: data})[0]
    result.tofile(args.out)
    print(f"Wrote {args.out}")


if __name__ == "__main__":
    main()
